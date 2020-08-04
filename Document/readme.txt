目录介绍：

- Project/BLE_Ota/Core/Inc/stm32wbxx_hal_conf.h		HAL 配置文件
- Project/BLE_Ota/Core/Inc/stm32wbxx_it.h     		中断处理程序头文件
- Project/BLE_Ota/Core/Inc/main.h      	           
- Project/BLE_Ota/STM32_WPAN/App/app_ble.h   	     
- Project/BLE_Ota/Core/Inc/app_common.h				所有模块通用定义头文件
- Project/BLE_Ota/Core/Inc/app_conf.h             	应用程序的参数配置文件
- Project/BLE_Ota/Core/Inc/app_entry.h   			应用程序的参数配置文件         
- Project/BLE_Ota/STM32_WPAN/App/ble_conf.h       	BLE服务配置
- Project/BLE_Ota/STM32_WPAN/App/ble_dbg_conf.h  	BLE跟踪BLE服务的配置
- Project/BLE_Ota/Core/Inc/hw_conf.h           		硬件配置	
- Project/BLE_Ota/Core/Inc/utilities_conf.h    		实用工具配置
- Project/BLE_Ota/Core/Src/stm32wbxx_it.c         	中断处理程序
- Project/BLE_Ota/Core/Src/main.c 					主程序
- Project/BLE_Ota/Core/Src/system_stm32wbxx.c		系统源文件
- Project/BLE_Ota/STM32_WPAN/App/app_ble.c 			BLE 配置文件实现
- Project/BLE_Ota/Core/Src/app_entry.c 				应用程序初始化
- Project/BLE_Ota/STM32_WPAN/Target/hw_ipcc.c		IPCC 驱动器
- Project/BLE_Ota/Core/Src/stm32_lpm_if.c			低功耗管理器接口		
- Project/BLE_Ota/Core/Src/hw_timerserver.c 		RTC定时器服务器
- Project/BLE_Ota/Core/Src/hw_uart.c 			 	UART 驱动器
- Project/BLE_Ota/STM32_WPAN/App/otas_app.c 		OTA服务管理


功能介绍：
BLE_OTA，采用的是自定义BLE service/char.它由三个characteristic组成：
第一个，base address，属性为写，由上位机发过来，被bootloader接收，写到自定义的这个BLE service的第一个characteristic；
第二个，是升级文件image的具体内容，属性也是写；
第三个，是一个indication属性的characteristic，它是在bootloader完成了固件升级后，要复位重启设备端的一个通知，给到OTA上位机。
通过这样一个自定义的BLE service，bootloader就可以实现来自上位机的新固件文件的接收，烧写、以及过程结束后的状态回复。 

另外一方面，应用程序，要在已有的BLE service中新增一个具有写属性的characteristic：“Reboot Request”，它包含三个信息：
reboot的方式，要擦除的起始扇区编号、以及要擦除的扇区个数。这样一个支持rebootrequest/重启请求的能力，会在该设备和客户端AP，
建立连接之前的广播阶段，表达出来。