Template for the em::Blocks IDE
============


This template for the em::Block IDE contains:
- STM32F4xx HAL Driver (the STM32CubeF4 new hardware abstraction layers)
- FreeRTOS V8.12
- Specific configuration for the STM32F4-Discovery board.


### Installation of the em::Blocks template

Copy the "STM32F4-Discovery-Template" in the Windows AppData directory for em::Blocks

```Batchfile 

xcopy /S /I STM32F4-Discovery-FreeRTOS %APPDATA%\EmBlocks\2.00\UserTemplates\STM32F4-Discovery-FreeRTOS

```

To create a new project in em::Blocks, use the "File / New / From template..." menu and select the new template. 
Then enter the target directory and the project name.
