STM32F4-Discovery
============


In this repository you can find several directories for the STM32F4-Discovery card. 

## Templates for the em::Blocks IDE

STM32F4-Discovery-FreeRTOS contains:
- STM32F4xx HAL Driver (the STM32CubeF4 new hardware abstraction layers)
- FreeRTOS V8.12
- Specific configuration for the STM32F4-Discovery board.

STM32F4-Discovery-HAL contains:
- STM32F4xx HAL Driver (the STM32CubeF4 new hardware abstraction layers)
- Specific configuration for the STM32F4-Discovery board.


### Installation of the em::Blocks template

Copy the "STM32F4-Discovery-xxx" in the Windows AppData directory for em::Blocks

```Batchfile 

xcopy /S /I STM32F4-Discovery-xxxx %APPDATA%\EmBlocks\2.00\UserTemplates\STM32F4-Discovery-xxxx
(where xxxx is the template type you want to copy)
```

To create a new project in em::Blocks, use the "File / New / From template..." menu and select the new template. 
Then enter the target directory and the project name.
