/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

#include<stdio.h>
#include<string.h>
#include "libIBus.h"
#include "rdk_dynamic_log.h"


/*
To build the test app, add test folder to the below lines
SUBDIRS = src include test
DIST_SUBDIRS = cfg src include test
To the file rdk_logger/generic/Makefile.am

How to test :

1. Run the test App dynamicLoggerTest in the box.
The binary can be copied to the box after compiling the test code by doing a bitbake for rdk-logger
with the above changes.
2. The test application has registered for dynamic logging updates with
Application Name :
 Application1
Module Name ------ SubModule Name ------ Registered Callback
ClosedCaptions1    NULL                  CC_LOG_ControlCB1
ClosedCaptions2    NULL                  CC_LOG_ControlCB2
ServiceManager     devicesettings        CC_LOG_ControlCB3
ServiceManager     hdmicec               CC_LOG_ControlCB4

Or

Application Name :
 Application2
Module Name ------ SubModule Name ------ Registered Callback
ClosedCaptions1    NULL                  CC_LOG_CallBack1
ClosedCaptions2    NULL                  CC_LOG_CallBack2
ServiceManager     devicesettings        CC_LOG_CallBack3
ServiceManager     hdmicec               CC_LOG_CallBack4

Or

Boundary testing test cases.

3. Execute the rdklogctrl tool with proper input parameters and check whether the
test application is showing correct print.

eg. If we execute the tool with following parameters
./rdklogctrl Application1 ClosedCaptions1 NULL DEBUG

The test application will print
TEST : Entered CC_LOG_ControlCB1
TEST : ##############Data obtained ################
TEST : moduleName : ClosedCaptions1 subComponentName : NULL loggingLevel : DEBUG log_status : 1

Similarly different combinations of input parameters can be tested.

*/

void CC_LOG_ControlCB1(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    printf("TEST : Entered CC_LOG_ControlCB1 \n");
    printf("TEST : ##############Data obtained ################\n");
    printf("TEST : moduleName : %s subComponentName : %s loggingLevel : %s log_status : %d\n",moduleName,subComponentName,loggingLevel,log_status);
}
void CC_LOG_ControlCB2(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    printf("TEST : Entered CC_LOG_ControlCB2 \n");
    printf("TEST : ##############Data obtained ################\n");
    printf("TEST : moduleName : %s subComponentName : %s loggingLevel : %s log_status : %d\n",moduleName,subComponentName,loggingLevel,log_status);
}
void CC_LOG_ControlCB3(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    printf("TEST : Entered CC_LOG_ControlCB3 \n");
    printf("TEST : ##############Data obtained ################\n");
    printf("TEST : moduleName : %s subComponentName : %s loggingLevel : %s log_status : %d\n",moduleName,subComponentName,loggingLevel,log_status);
}
void CC_LOG_ControlCB4(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    printf("TEST : Entered CC_LOG_ControlCB4 \n");
    printf("TEST : ##############Data obtained ################\n");
    printf("TEST : moduleName : %s subComponentName : %s loggingLevel : %s log_status : %d\n",moduleName,subComponentName,loggingLevel,log_status);
}
void CC_LOG_CallBack1(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    printf("TEST : Entered CC_LOG_CallBack1\n");
    printf("TEST : ##############Data obtained ################\n");
    printf("TEST : moduleName : %s subComponentName : %s loggingLevel : %s log_status : %d\n",moduleName,subComponentName,loggingLevel,log_status);
}
void CC_LOG_CallBack2(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    printf("TEST : Entered CC_LOG_CallBack2\n");
    printf("TEST : ##############Data obtained ################\n");
    printf("TEST : moduleName : %s subComponentName : %s loggingLevel : %s log_status : %d\n",moduleName,subComponentName,loggingLevel,log_status);
}
void CC_LOG_CallBack3(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    printf("TEST : Entered CC_LOG_CallBack3\n");
    printf("TEST : ##############Data obtained ################\n");
    printf("TEST : moduleName : %s subComponentName : %s loggingLevel : %s log_status : %d\n",moduleName,subComponentName,loggingLevel,log_status);
}
void CC_LOG_CallBack4(const char *moduleName, const char *subComponentName, const char *loggingLevel, int log_status)
{
    printf("TEST : Entered CC_LOG_CallBack4\n");
    printf("TEST : ##############Data obtained ################\n");
    printf("TEST : moduleName : %s subComponentName : %s loggingLevel : %s log_status : %d\n",moduleName,subComponentName,loggingLevel,log_status);
}

#define IARM_BUS_DYNAMIC_LOGGER_TESTAPP "LOG_TESTER"

void main()
{
    IARM_Bus_Init(IARM_BUS_DYNAMIC_LOGGER_TESTAPP);
    IARM_Bus_Connect();
    rdk_dynamic_logger_initialize();
    int i = 1;
    char appName[] = "Apppppppppppppppppppppppppppppppppppppppppppppppppppppplication";
    char module1[] = "Moduuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuule1";
    char module2[] = "Moduuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuule2";
    char subModule1[] = "SubModuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuule1";
    char subModule2[] = "SubModuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuule2";

    printf("Thanks for using Dynamic Logger TestApp \n");
    printf("Please select the App name\n 1 - Application1   2 - Application2 3 - Boundary testing cases \n");
    scanf("%d", &i);

    switch(i)
    {
    case 1:

        printf("Registering app Application1 \n");
        fflush(stdout);
        rdk_dynamic_logger_setAppName("Application1");
        rdk_dynamic_logger_registerLogCtrlComp("ClosedCaption1", NULL, CC_LOG_ControlCB1);
        rdk_dynamic_logger_registerLogCtrlComp("ClosedCaption2", NULL, CC_LOG_ControlCB2);
        rdk_dynamic_logger_registerLogCtrlComp("ServiceManager", "devicesettings", CC_LOG_ControlCB3);
        rdk_dynamic_logger_registerLogCtrlComp("ServiceManager", "hdmicec", CC_LOG_ControlCB4);

    break;

    case 2 :

        printf("Registering app Application2 \n");
        fflush(stdout);
        rdk_dynamic_logger_setAppName("Application2");
        rdk_dynamic_logger_registerLogCtrlComp("ClosedCaption1", NULL, CC_LOG_CallBack1);
        rdk_dynamic_logger_registerLogCtrlComp("ClosedCaption2", NULL, CC_LOG_CallBack2);
        rdk_dynamic_logger_registerLogCtrlComp("ServiceManager", "devicesettings", CC_LOG_CallBack3);
        rdk_dynamic_logger_registerLogCtrlComp("ServiceManager", "hdmicec", CC_LOG_CallBack4);

    break;

    case 3 :

        printf("Registering app %s for boundary testing \n",appName);
        fflush(stdout);
        rdk_dynamic_logger_setAppName(appName);
        printf("Registering Module : %s (Length : %d)& SubModule : NULL\n", module1, strlen(module1));
        rdk_dynamic_logger_registerLogCtrlComp(module1, NULL, CC_LOG_CallBack1);
        printf("Registering Module : %s (Length : %d)& SubModule : NULL\n", module2, strlen(module2));
        rdk_dynamic_logger_registerLogCtrlComp(module2, NULL, CC_LOG_CallBack2);
        printf("Registering Module : ServiceManager & SubModule : %s(Length : %d)\n", subModule1, strlen(subModule1));
        rdk_dynamic_logger_registerLogCtrlComp("ServiceManager", subModule1, CC_LOG_CallBack3);
        printf("Registering Module : ServiceManager & SubModule : %s(Length : %d)\n", subModule2, strlen(subModule2));
        rdk_dynamic_logger_registerLogCtrlComp("ServiceManager", subModule2, CC_LOG_CallBack4);

    break;

    default:
    break;
    }
    printf("Test Modules and SubModules registered. Ready to use rdklogctrl utility ..\n");
    while(1)
    {
        printf("Heartbeat ..\n");
        fflush(stdout);
        sleep(10);
    }

    rdk_dynamic_logger_unRegisterLogCtrlComp("ServiceManager", "hdmicec");
    rdk_dynamic_logger_unRegisterLogCtrlComp("ClosedCaption2", NULL);
    rdk_dynamic_logger_unRegisterLogCtrlComp("ClosedCaption1", NULL);
    rdk_dynamic_logger_unRegisterLogCtrlComp("ServiceManager", "devicesettings");
    rdk_dynamic_logger_unRegisterLogCtrlComp(module1, NULL);
    rdk_dynamic_logger_unRegisterLogCtrlComp(module2, NULL);
    rdk_dynamic_logger_unRegisterLogCtrlComp("ServiceManager", subModule1);
    rdk_dynamic_logger_unRegisterLogCtrlComp("ServiceManager", subModule2);

    rdk_dynamic_logger_unInitialize();
    IARM_Bus_Disconnect();
    IARM_Bus_Term();
    return;
}
