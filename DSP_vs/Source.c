#include <stdio.h>
#include <stdlib.h>

#define SIG_LENGTH      320U

extern double InputSignal_f32_1kHz_15kHz[320];

double calc_signal_mean(double* sig_src_arr, int sig_lenght);

double MEAN;

int main()
{
    MEAN = calc_signal_mean(&InputSignal_f32_1kHz_15kHz[0], SIG_LENGTH);

    printf("\n\n Mean = %f\n\n\n", MEAN);

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