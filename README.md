---
typora-root-url: ./picture
---

1. English version of the README -> please [click here](./README-EN.md)

  Dobot   TCP-IP-CR-CPP   二次开发api接口 （ [TCP-IP-CR-CPP English README](https://github.com/Dobot-Arm/TCP-IP-CR-CPP) ）

  # 1 简介

  TCP-IP-CR-CPP   是为 Dobot 公司旗下基于TCP/IP协议的C++的封装设计的软件开发套件。它基于 C/C++ 语言开发，通过socket与机器终端进行Tcp连接， 遵循Dobot-TCP-IP控制通信协议，  并为用户提供了易用的  C/C++ 的api接口。通过 TCP-IP-CR-CPP ，用户可以快速地连接Dobot机器并进行二次开发对机器的控制与使用。

  TCP-IP-CR-CPP  包括了 

  1.  api和CPPdemo,   api目录包含了 CR 的相关功能封装的各个类，基于c++编写的。    

  2.  cpp-demo包含了  Windows/Linux 示例以及 示例

  3.  api/rapidjson是[腾讯的json](https://github.com/Tencent/rapidjson)解析库。

  ## 前置依赖

  * Ubuntu 14.04/Ubuntu 16.04/Ubuntu 18.04, x86 和 ARM (Nvidia TX2)

  * Windows 7/10, Visual Studio 2015 Update3/2017/2019

  * C++11 编译器

    此API接口与Demo适用于V3系列的3.5.5.0及以上控制器版本

  

  ##  版本和发布记录

  ###  当前版本

  |   版本   |  修改日期  |
  | :------: | :--------: |
  | v1.0.0.0 | 2023-11-20 |

  
  

  # 2. TCP-IP-CR-CPP 控制协议

  由于基于TCP/IP的通讯具有成本低、可靠性高、实用性强、性能高等特点；许多工业自动化项目对支持TCP/IP协议控制机器人需求广泛，因此 CR 机器人将设计在TCP/IP协议的基础上，提供了丰富的接口用于与外部设备的交互；有关协议更详细的信息请查阅**[《越疆TCPIP控制协议文档6AXis-V3](https://github.com/Dobot-Arm/TCP-IP-Protocol-6AXis-V3)》**

  

  ## 3. 获取并构建TCP-IP-CR-CPP

  1. 从dobot  GitHub 获取越疆Dobot  TCP-IP-CR-CPP二次开发api程序

     ```bash
     `git clone https://github.com/Dobot-Arm/TCP-IP-CR-CPP.git`
     ```

  &ensp;&ensp;&ensp;&ensp;***说明：***参考对应的 README.md 文档使用；

  &ensp;

  ## 4. 文件以及类的说明

  1. api目录包含了CR的相关功能封装的各个类，基于c++编写的。

  2. api/rapidjson是[腾讯的json](https://github.com/Tencent/rapidjson)解析库。

  3. api目录中的类说明：

     | Parameter       | Default Value                                       |
     | --------------- | --------------------------------------------------- |
     | BitConverter    | 封装了字节与基础类型的转换                          |
     | DescartesPoint  | 笛卡尔坐标结构体封装                                |
     | JointPoint      | 关节点坐标结构体封装                                |
     | FeedbackData    | 反馈数据结构体封装                                  |
     | ErrorInfoBean   | 错误信息封装                                        |
     | ErrorInfoHelper | 错误信息帮助类                                      |
     | DobotClient     | 基于tcp通信的接口类，封装了通信的基础业务           |
     | Dashboard       | 派生于DobotClient，实现了具体的机器人基本功能       |
     | DobotMov        | 派生于DobotClient，实现了具体的机器人运动功能       |
     | Feedback        | 派生于DobotClient，实现了具体的机器人反馈的具体业务 |
     |                 |                                                     |

  4. `alarm_controller.json`警告报警配置文件,`alarm_servo.json`伺服报警配置文件。

  5. `Form.h`,`Form.cpp`,`Form.ui`,`main.cpp`,`CppDemo.pro`是基于Qt实现的UI。

  

  **CDobotClient**  

   基于tcp通信的接口类，提供对机器的tcp连接，关闭，获取ip，端口等功能， 封装了通信的基础业务。

  ```c++
      class CDobotClient
      {
      public:
       }
  ```

  

  **Dashboard**  

  ​      派生于DobotClient，  能发送一些设置相关的控制指令给机器人。实现了具体的机器人基本功能。  

  ```c++
   class CDashboard : public CDobotClient
      {
      public:
       }
  ```

  **DobotMov**  

  派生于DobotClient， 能发送一些运动相关的运动指令给机器人，实现了具体的机器人运动功能。  

  ```c++
    class CDobotMove : public CDobotClient
      {
      public:
    }    
  ```

  **Feedback**

  派生于DobotClient，实现了具体的机器人反馈的具体业务，能实时反馈机器人的状态信息。

  ```c++
      class CFeedbackData
      {
      public:
      };
  ```

   **具体使用详情请查看代码示例PythonExample.py和Demo示例**

  

  # 5. 常见问题

  问题一：  Tcp连接  29999/30003端口无法连接或者连接后无法下发指令

   解决方法：  如控制器版本是3.5.6.0版本以下，可尝试升级控制器为3.5.6.1版本及以上版本。 如机器已经是3.5.6.1版本及以上，可将问题现象和操作反馈给技术支持

  

  问题二： Tcp连接过程中  29999控制端口能发送指令，30003运动端口发送不了指令

   解决方法：  运动队列被堵塞，尝试用29999端口下发clearerror()和 continue()指令来重新开启队列

  

  问题三：怎么判断机器运动指令是否到位

  解决方法：  可通过下发sync指令来判断机器运动指令是否到位

  ​                     可通过对比目标点位笛卡尔坐标值和机器实际笛卡尔坐标值来判断是否到位

  

  # 6. 示例

  * Dobot-Demo 实现Tcp对机器的控制等交互，分别对控制端口，运动端口，反馈端口进行tcp连接，通过机器运动指令完成状态来进行下发指令，且对机器异常状态进行处理等功能。

    

  1.  主线程：分别对机器控制端口，运动端口，反馈端口进行连接。给机器使能，MovL移动指令等动作

  ![](/main.png)

  2.  反馈状态线程：实时反馈机器的状态信息

  ![](/feed.png)

  3. 机器运动线程： 给机器下发运动指令

  ![](/move.png)

  4.  异常处理线程：对机器异常状态进行判断和处理动作

  ![](/excetion.png)

  **Demo运行的操作步骤时序如下图所示 ：**

  1. 从GitHub 获取越疆Dobot  TCP-IP-CR-CPP  二次开发Api程序

     ```bash
     `git clone https://github.com/Dobot-Arm/TCP-IP-CR-CPP.git
     ```

  2. 通过LAN1网口-连接机器端，设置本机机器IP地址为192.168.5.X  网段

     控制面板>>网络>> Internet>>网络连接  

     ![](/netConnect.png)

     

     选择连接的以太网  >>  点击右键  >> 属性  >>   Internet协议版本(TCP/IPV4)

     修改ip地址为192.168.5.X网段IP

     <img src="/updateIP.png" style="zoom:80%;" />

     

  3. 连接上位机DobotStudio Pro，连接机器，把机器模式切换至TCP/IP模式

     ![](/checkTcpMode.png)

     

  4. 运行程序

     1. 从Dobot  GitHub 获取越疆Dobot  TCP-IP-CR-CPP 二次开发api程序

        ```bash
        `git clone https://github.com/Dobot-Arm/TCP-IP-CR-CPP.git`
        ```

     &ensp;&ensp;&ensp;&ensp;

     2. 进入目录  TCP-IP-CR-CPP/CppDemo/  文件夹进行编译Demo程序

     ```bash
     cd  TCP-IP-CR-CPP/CppDemo/
     bash compileDemo.sh
     ```

     

     3. 运行Demo程序

     ```bash
     bash runDemo.sh
     ```

     

    **常见问题：**

  ​     **问题一： 请确保机器处于Tcp/IP模式'**

     

  ​    **问题二： 确认Demo中 不同机型（CR）对应的笛卡尔坐标**

  

  **运行示例前请确保机器处于安全位置，防止机器发生不必要的碰撞**

  
