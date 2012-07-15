/*
 * Copyright 2012, Yunjie Lu.  All rights reserved.
 * https://github.com/lyjdamzwf/chaos
 *
 * Use of this source code is governed by a BSD-style
 * license that can be found in the License file.
 */

#ifndef _TIMEUTIL_H_
#define _TIMEUTIL_H_

/*! 
 *  @file           time_util.h
 *  @author         yunjie.lu
 *  @email          lyjdamzwf@gmail.com
 *  @weibo          http://weibo.com/crazyprogramerlyj
 *  @date
 *  @brief
 *  @last changed
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <sys/time.h>

namespace chaos
{

namespace utility
{

#define TIMEZONE -28800

/**
  * usage: sharp_day(0,time)   --time那一天的0点的时间戳
  *        sharp_day(-1,time) --time那一天的前一天0点的时间戳
  *        sharp_day(1,time)  --time那一天的第二天0点的时间戳
  *        sharp_hour(0,time) --time所在小时整点的时间戳
  *        sharp_hour(-1,time) --time所在小时整点的前一小时整点的时间戳
  *        sharp_hour(1,time) --time所在小时整点的后一小时整点的时间戳
  * para c:   与cur比较的时间差
  * para cur: 时间基准
**/
class time_util_t
{
public:
    static inline void init() { tzset(); }
    static inline uint32_t now() { return static_cast<uint32_t>(time(NULL)); }
    static inline uint32_t sharp_day(int c_ = 0, uint32_t cur_ = now())
    {
        uint32_t tmptm = (cur_ + timezone) / 86400 * 86400 + timezone;
        if(tmptm > cur_)
            tmptm -= 86400;
        else if(tmptm + 86400 <= cur_)
            tmptm += 86400;
        return tmptm + c_ * 86400;
    }
    static inline uint32_t sharp_hour(int c_, uint32_t tm_ = now())
    {
        return (tm_ + c_ * 3600) / 3600 * 3600;
    }
    static inline uint32_t sharp_minute(int c_, uint32_t tm_ = now())
    {
        return (tm_ + c_ * 60) / 60 * 60;
    }

    static inline tm get_now_tm()
    {
        time_t now=time(NULL);
        tm now_tm;
        localtimes(now,TIMEZONE,&now_tm);
        return now_tm;
    }

    static inline tm get_tm_by_int(uint32_t time_)
    {
        tm watch_time;
        localtimes((time_t)time_, TIMEZONE, &watch_time);
        return watch_time;
    }

    /**
      * yunjie: 多线程安全同步地获取tm结构
    **/
    static void  localtimes(time_t time,long timezone,struct tm *tm_time)
    {
        const char Days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        uint32_t n32_Pass4year;
        int32_t n32_hpery;
        //计算时差
        time=time-timezone;
        if(time < 0)
        {
            time = 0;
        }
        //取秒时间
        tm_time->tm_sec=(int)(time % 60);    time /= 60;
        //取分钟时间
        tm_time->tm_min=(int)(time % 60);    time /= 60;
        //取过去多少个四年，每四年有 1461*24 小时
        n32_Pass4year=((unsigned int)time / (1461L * 24L));
        //计算年份
        tm_time->tm_year=(n32_Pass4year << 2)+70;
        //四年中剩下的小时数
        time %= 1461L * 24L;
        //校正闰年影响的年份，计算一年中剩下的小时数
        for (;;)
        {
            //一年的小时数
            n32_hpery = 365 * 24;
            //判断闰年
            if ((tm_time->tm_year & 3) == 0)
            {
                //是闰年，一年则多24小时，即一天
                n32_hpery += 24;
            }
            if (time < n32_hpery)
            {
                break;
            }
            tm_time->tm_year++;
            time -= n32_hpery;
        }
        //小时数
        tm_time->tm_hour=(int)(time % 24);
        //一年中剩下的天数
        time /= 24;
        //假定为闰年
        time++;
        //校正润年的误差，计算月份，日期
        if ((tm_time->tm_year & 3) == 0)
        {
            if (time > 60)
            {
                time--;
            }
            else
            {
                if (time == 60)
                {
                    tm_time->tm_mon = 1;
                    tm_time->tm_mday = 29;
                    return ;
                }
            }
        }
        //计算月日
        for (tm_time->tm_mon = 0; Days[tm_time->tm_mon] < time;tm_time->tm_mon++)
        {
            time -= Days[tm_time->tm_mon];
        }
        tm_time->tm_mday = (int)(time);
        return;
    }
};

}

}

#endif // _TIMEUTIL_H_

