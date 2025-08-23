import argparse
import asyncio

from bleak import BleakClient, BleakScanner

esp32_LOCAL_NAME = "BLE-LAB18"  # Correct device name here
LED_UUID = "19b10001-e8f2-537e-4f6c-d104768a1214"

async def find_ble_device():
    print("Scanning for 5 seconds, please wait...")

    devices = await BleakScanner.discover()

    for device in devices:
        # device.name is often the local name
        print(device.name)
        if device.name == esp32_LOCAL_NAME:
            print(f"Found ESP32 device: {device.name} [{device.address}]")
            return device

    print("Could not find the ESP32 device")
    return None

async def runmain():
    device = await find_ble_device()
    if device is None:
        return

    async with BleakClient(device.address) as client:
        print(f"Connected to {device.name}")
        while True:
            cmd = input("Enter command (w/a/s/d/b or exit): ")
            if cmd.lower() == "exit":
                print("Exiting...")
                break
            if cmd.lower() in ['w', 'a', 's', 'd', 'b']:
                await client.write_gatt_char(LED_UUID, cmd.encode())
                print(f"Sent command: {cmd}")
            else:
                print("Invalid command, try again.")

                
if __name__ == "__main__":
    asyncio.run(runmain())
