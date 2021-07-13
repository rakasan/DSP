#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#define SIG_LENGTH      320U

extern double InputSignal_f32_1kHz_15kHz[320];

double calc_signal_mean(double* sig_src_arr, int sig_lenght);

double calc_signal_variance(double* sig_src_arr, double sig_mean, int sig_length);

double MEAN;

double VARIANCE;

int main()
{
    MEAN = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);

    VARIANCE = calc_signal_variance(&InputSignal_f32_1kHz_15kHz[0], MEAN, SIG_LENGTH);

    printf("\n\n Variance = %f\n\n\n", VARIANCE);

    return 0;
}

double calc_signal_mean(double* sig_src_arr, int sig_lenght)
{
    double _mean = 0.0;
    for (int i = 0; i < sig_lenght; i++)
    {
        _mean = _mean + sig_src_arr[i];
    }

    _mean = (_mean / (double)sig_lenght);

    return _mean;
}

double calc_signal_variance(double* sig_src_arr, double sig_mean, int sig_length)
{
    double _variance = 0.0;

    for (int i = 0; i < sig_length; i++)
    {
       // _variance = _variance + ((sig_src_arr[i] - sig_mean) * (sig_src_arr[i] - sig_mean));
        _variance = _variance + pow((sig_src_arr[i] - sig_mean), 2);
    }

    _variance = _variance / (double)((double)sig_length - 1);

    return _variance;
}