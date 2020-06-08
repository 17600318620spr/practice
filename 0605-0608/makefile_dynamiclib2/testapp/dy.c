#include "stdio.h"			/* 包含标准输入输出文件 */
#include "stdlib.h"
#include "dlfcn.h" 			/* 包含动态链接功能接口文件 */
#define SOFILE "../lib/libmy.so" 	/* 指定动态链接库名称 */
#define SHARED 				/* 定义宏,确认共享,以便引用动态函数 */
#include "datetime.h" 			/* 包含用户接口文件 */

int main()
{
	DATETYPE d;
	TIMETYPE t;
	void *dp;
	char *error;

	puts("获取当前时间");

	dp=dlopen(SOFILE, RTLD_LAZY); /* 打开动态链接库 */
	if (dp==NULL) /* 若打开失败则退出 */
	{
		fputs(dlerror(), stderr);
		exit(1);
	}

	getdate=dlsym(dp, "getdate"); /* 定位取日期函数 */

	error=dlerror(); /* 检测错误 */
	if (error) /* 若出错则退出 */
	{
		fputs(error, stderr);
		exit(1);
	}

	getdate(&d); /* 调用此共享函数 */

	printf("当前日期: %04d-%02d-%02d\n",d.year,d.mon,d.day);

	gettime=dlsym(dp,"gettime"); /* 定位取时间函数 */

	error=dlerror(); /* 检测错误 */
	if (error) /* 若出错则退出 */
	{
		fputs(error,stderr);
		exit(1);
	}

	gettime(&t); /* 调用此共享函数 */

	printf("当前时间: %02d:%02d:%02d\n",t.hour,t.min,t.sec);

	dlclose(dp); /* 关闭共享库 */

	exit(0); /* 成功返回 */
}
