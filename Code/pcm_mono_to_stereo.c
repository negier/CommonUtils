#include <stdio.h>
void pcmMonoToStereo(const char*,const char*);
int main(){
	const char *pcmPath = "/home/duan/Desktop/mic_1575543513312.pcm";
	const char *newPcmPath = "/home/duan/Desktop/mic_new.pcm";
	pcmMonoToStereo(pcmPath,newPcmPath);
}
/*
 * 单声道的PCM转双声道
 */
void pcmMonoToStereo(const char* pcmPath,const char* newPcmPath){
	FILE* pcm;
	if((pcm =  fopen(pcmPath,"r+"))==NULL){
		printf("传入的pcm文件地址有误");
		return;
	}
	
	//为了获取文件大小
        fseek(pcm,0L,SEEK_END); 
        long fileSize = ftell(pcm);
        rewind(pcm);
        
	FILE* newPcm =  fopen(newPcmPath,"w");
        char newPcmArray[fileSize*2]; //单声道转双声道，自然大小要翻倍

        int p=0;
        int i=0,m = 0;
        while((p=fgetc(pcm))!=EOF){ // fgetc返回的是一个unsigned char，一个字节
                if(m==2){
                        //复制值到另一个声道
                        newPcmArray[i] = newPcmArray[i-2];
                        newPcmArray[i+1] = newPcmArray[i-1];
                       
		       	i += 2;
                        m = 0;
                }
                newPcmArray[i] = p;
                m++;
                i++;
        }
	fwrite(&newPcmArray,sizeof(newPcmArray),1,newPcm);
	
	fclose(pcm);
	fclose(newPcm);
}
