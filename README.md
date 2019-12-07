# CommonUtils
- [闰年](https://github.com/negier/CommonUtils/blob/master/Code/leapyear.c)（%取模运算符的最佳实践）
- [大写转小写](https://github.com/negier/CommonUtils/blob/master/Code/lower.c)（利用字母在ASCII字符集中的连续性）
- [返回指定位置的二进制](https://github.com/negier/CommonUtils/blob/master/Code/getbits.c)（&|~位运算的最佳实践）

## PCM
PCM双声道按照“左右 左右 左右 ...”的顺序存储每个采样点两个声道的数据
如不嫌弃，可用我录的[单声道pcm](https://github.com/negier/CommonUtils/tree/master/res/mic_1575543513312.pcm)测试（16bit，44.1kHZ）
- [PCM单声道转立体声](https://github.com/negier/CommonUtils/blob/master/Code/pcm_mono_to_stereo.c)（尤其适用于移动设备，因为移动设备录制的双声道都是伪立体声）
