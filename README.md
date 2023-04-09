# Pj of Sfsnake
OOP Course (COMP130135.04 Spring 2021) Project of Fudan University.

## 环境搭建

——推荐使用虚拟机在linux上运行，windows下配置较为繁琐

```bash
sudo apt-get install libsfml-dev
```



## 编译运行

```bash
mkdir build
cd build
cmake ..
```

```bash
make
```

```bash
./main
```



## 代码框架

```bash
Sfsnake
  |__ Fonts 		           //游戏文字所用到的字体
  |__ img                  //所用到的图片文件 目前只有用作头部的表情包
 	 	|__ head.png  
  |__ Music 		           //游戏所需的音乐
  		|__ bg_music.wav     //背景音乐
  |__ Sounds               //运行动作所需的声音
        |__ die.wav   	   //阵亡音乐
  		|__ pickup.wav       //得分音乐
  |__src                   //实现代码
```



## 游戏设计说明

### 1.移动方式：
保留四个方向控制蛇的移动，增加了鼠标控制蛇移动的功能。用鼠标左键单击游戏界面中的某个位置，蛇会朝着这个方向移动。但如果转弯角度过大（接近180°），可能引发死亡判定。
### 2.水果控制：
现增加黑色、棕色、红色、蓝色、绿色、共5 种水果，且贪食蛇吃了黑色、棕色水果不增加其长度，红色、蓝色、绿色水果增加的长度分别为3、2、1；增加的长度在贪食蛇的尾部—假设初始是叠加在一起的。系统随机生成上述5 种水果，保持黑色和褐色水果所占比例为25%，其他的占75%。
### 3.绘制精灵版本的贪食蛇
更改贪食蛇的绘制方法，头部使用某表情包图片，通过sprite 进行绘制，其余部分使用黄色圆叠加黑色的矩形块绘制
### 4. 整体界面的修改
增加了界面选择界面，出现在开始界面和游戏界面之间。用户可选择背景的颜色（提供白色、黑色、褐色三种）；也可以设置网格的颜色（提供白色、黑色、褐色三种），并可以选择关闭网格。若用户不设置，初始化为黑背景、白网格。
### 5.其他功能
增加了死亡判定条件，当蛇行至四个边界处，会引发死亡判定。



## License

The MIT License (MIT)

Copyright (c) <2013>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
