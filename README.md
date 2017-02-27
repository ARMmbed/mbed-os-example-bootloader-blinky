# Getting started with Bootloader Blinky on mbed OS

This example shows how to build and use an application with a prebuilt bootloader. For steps on how to create the bootloader, see [mbed-os-example-bootloader](https://github.com/ARMmbed/mbed-os-example-bootloader).

## Required hardware
* A supported board - [K64F](https://developer.mbed.org/platforms/ublox-EVK-ODIN-W2/), [Nucleo F429ZI](https://developer.mbed.org/platforms/ST-Nucleo-F429ZI/) or [K64F](https://developer.mbed.org/platforms/FRDM-K64F/).
* CI test shield.
* SD card.

## Import the example application

From the command-line, import the example:

```
mbed import mbed-os-example-bootloader-blinky
cd mbed-os-example-bootloader-blinky
```

## Set up application to use bootloader

All supported boards mentioned above are set up to use bootloader with a CI test shield.

To either use a different board or a different SD card slot, you must rebuild the bootloader and update the application.
To do this:

1. Create a bootloader for your board in the project [mbed-os-example-bootloader](https://github.com/ARMmbed/mbed-os-example-bootloader).
2. Update your board to use the newly created booloader in mbed_app.json.

```
    "target_overrides": {
        ...
        "NUCLEO_F429ZI": {
            "target.bootloader_img": "bootloader/NUCLEO_F429ZI.bin"
        },
        ...
```

## Now compile

Invoke `mbed compile`, and specify the name of your platform and your favorite toolchain (`GCC_ARM`, `ARM`, `IAR`). For example, for the ARM Compiler 5:

```
mbed compile -m NUCLEO_F429ZI -t ARM
```

Your PC may take a few minutes to compile your code. At the end, you see the following result:

```
Merging Regions:
  Filling region application with .\BUILD\NUCLEO_F429ZI\ARM\mbed-os-example-bootloader_application.bin
  Padding region application with 0x11420 bytes
Space used after regions merged: 0x20000
+-----------------------------+-------+-------+-------+
| Module                      | .text | .data |  .bss |
+-----------------------------+-------+-------+-------+
| Misc                        | 18481 |    24 |  1268 |
| drivers                     |  2132 |     8 |   184 |
| features/FEATURE_LWIP       |    46 |     0 | 12560 |
| features/filesystem         | 12756 |    12 |   540 |
| hal                         |   414 |     8 |     0 |
| hal/TARGET_FLASH_CMSIS_ALGO |   520 |    28 |     0 |
| platform                    |  2759 |    32 |   380 |
| rtos                        |   144 |     8 |     0 |
| rtos/rtx                    |  6954 |   100 |  8396 |
| targets/TARGET_STM          | 15560 |   568 |   736 |
| Subtotals                   | 59766 |   788 | 24064 |
+-----------------------------+-------+-------+-------+
Allocated Heap: unknown
Allocated Stack: unknown
Total Static RAM memory (data + bss): 24852 bytes
Total RAM memory (data + bss + heap + stack): 24852 bytes
Total Flash memory (text + data + misc): 60554 bytes

Image: .\BUILD\NUCLEO_F429ZI\ARM\mbed-os-example-bootloader.bin
```

## Program bootloader and application

1. Connect your mbed device to the computer over USB.
1. Copy the binary file to the mbed device.
1. Press the reset button to start the program.

The LED on your platform turns on and off.

## Program application using SD card

1. Connect the SD card to your computer.
1. Copy the application binary (mbed-os-example-bootloader-blinky_application.bin) to the root of the SD card.
1. Remove the SD card from your PC, and plug it into the mbed board.
1. Press the reset button to start the firmware update.

If a terminal is open, the following prints:

```
Firmware update found
Starting application
```

You then see the LED on your platform turning on and off.

## Troubleshooting

1. Make sure `mbed-cli` is working correctly and its version is `>1.0.0`.

 ```
 mbed --version
 ```

 If not, you can update it:

 ```
 pip install mbed-cli --upgrade
 ```

2. If using Keil MDK, make sure you have a license installed. [MDK-Lite](http://www.keil.com/arm/mdk.asp) has a 32 KB restriction on code size.