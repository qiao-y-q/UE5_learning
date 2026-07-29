这件事困扰了我三天花费了大量的时间，也试过了很多办法但是无法根治第二天启动的时候依然会报错

我觉得这类事情在我以后的职业生涯或者生活中可能会多次碰见，所以记录下来留作日志





\# UE 5.7.4 缓存问题解决记录



\*\*日期\*\*：2026-07-29



\*\*问题描述\*\*：

UE 5.7.4 启动时报错 `Unable to use default cache graph ... because there are no writable nodes available`，引擎无法启动。



\*\*原因分析\*\*：

Windows 用户名（`良月十三`）包含中文字符，UE 5.7 默认使用的 Zen 缓存系统在处理包含中文的路径时出现编码问题，导致无法写入缓存文件。



\*\*解决步骤\*\*：



1\. \*\*设置系统环境变量\*\*

&#x20;  - 变量名：`UE-LocalDataCachePath`

&#x20;  - 变量值：`C:\\UE\_DDC`

&#x20;  - 作用：通知引擎将缓存写入纯英文路径，绕过中文用户名路径



2\. \*\*修改引擎配置文件\*\*

&#x20;  - 文件位置：`C:\\Program Files\\Epic Games\\UE\_5.7\\Engine\\Config\\BaseEngine.ini`

&#x20;  - 替换所有 `%ENGINEVERSIONAGNOSTICUSERDIR%DerivedDataCache` 为 `C:/UE\_DDC`

&#x20;  - 替换所有 `%GAMEDIR%DerivedDataCache` 为 `C:/UE\_DDC`



3\. \*\*清理旧缓存\*\*

&#x20;  - 删除 `C:\\Users\\月月十三\\AppData\\Local\\UnrealEngine\\5.7`

&#x20;  - 删除 `C:\\Users\\月月十三\\AppData\\Local\\UnrealEngine\\Common\\DerivedDataCache`

&#x20;  - 删除 `C:\\Users\\月月十三\\AppData\\Local\\UnrealEngine\\Common\\Zen`



4\. \*\*重启验证\*\*

&#x20;  - 重启电脑使环境变量生效

&#x20;  - 重新启动 UE 5.7.4，引擎正常打开



\*\*当前状态\*\*：

UE 5.7.4 可正常启动，缓存路径已指向 `C:\\UE\_DDC`，不再依赖中文用户名路径。



\*\*涉及的关键文件/路径\*\*：

\- `C:\\Program Files\\Epic Games\\UE\_5.7\\Engine\\Config\\BaseEngine.ini`

\- `C:\\UE\_DDC`（新建的缓存目录）

\- `UE-LocalDataCachePath`（环境变量）



\*\*备注\*\*：

本记录在问题解决后整理上传，用于保留解决过程和防止未来重复踩坑。

