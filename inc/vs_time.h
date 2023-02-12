#ifndef VS_TIME_H
#define VS_TIME_H

#if defined(__x86_64__)
typedef long long	vs_time_t;
#else
typedef long int	vs_time_t;
#endif

#endif
