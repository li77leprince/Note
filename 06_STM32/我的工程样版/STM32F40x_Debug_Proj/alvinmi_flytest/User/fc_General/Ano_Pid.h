#ifndef	__ANO_PID_H__
#define __ANO_PID_H__

#include "Ano_FcDate.h"

typedef struct
{
	u8 fb_d_mode;
	
	float kp;			// 比例系数
	float ki;			// 积分系数
	float kd_ex;		// 微分系数
	float kd_fb;		// previous_d 微分先行
//	float inc_hz;		// 不完全微分低通系数
//	float k_inc_d_norm;	// Incomplete  不完全微分 归一 (0,1), 即 0~1
	float k_ff;			// 前馈
}_PID_arg_st;

typedef struct
{
	float err;
	float exp_old;
	float feedback_old;
	
	float fb_d;
	float fb_d_ex;
	float exp_d;
//	float err_d_lpf;
	float err_i;
	float ff;
	float pre_d;
	
	float out;
	
}_PID_val_st;

// PID_计算 声明
float PID_calculate(float T,		// 周期
					float in_ff,	// 前馈值
					float expect,	// 期望值(设定值)
					float feedback,	// 反馈值
					_PID_arg_st *pid_arg,	// PID 参数结构体
					_PID_arg_st *pid_val,	// PID 数据结构体
					float inte_d_lim,		// 积分误差限幅
					float inre_lim			// integration limit, 积分限幅
					);

#endif


