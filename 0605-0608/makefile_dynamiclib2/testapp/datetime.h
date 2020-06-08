#ifndef __DATETIME_H
#define __DATETIME_H

/* 日期结构 */
typedef struct
{
	int year;
	int mon;
	int day;
}DATETYPE;

/* 时间结构 */
typedef struct
{
	char hour;
	char min;
	char sec;
}TIMETYPE;

/* 函数原型说明 */
#ifdef SHARED
int (*getdate)(DATETYPE *d);
#else
int getdate(DATETYPE *d);
#endif

#ifdef SHARED
int (*gettime)(TIMETYPE *t);
#else
int gettime(TIMETYPE *t);
#endif

#endif
