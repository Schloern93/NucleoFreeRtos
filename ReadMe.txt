Starten des DEbuggens von der Commandozeile
- openocd -f config/stlink.cfg -f config/stm32g4x.cfg
- Neues Terminal GDB starten
- arm-none-eabi-gdb CmakeBuild/BlinkExample.elf
- target remote localhost:3333

Debug befehle
- monitor halt
- monitor reset
-  info register


disassemble /m Reset_Handler