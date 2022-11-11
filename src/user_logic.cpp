#include "user_logic.h"

//#include "ei_run_impulse.h"

void run_user_logic_after_inference(ei_impulse_result_t *result)
{
  // add logic
}

void start_user_impulse()
{
    // if you want your impulse library to run at startup
    //ei_start_impulse(false, false);
}

void user_inference_stopped()
{
    // if you want to run user logic when state is set to stopped
    ei_printf("INFERENCE_STOPPED....\n");
}
void user_inference_waiting()
{
    // if you want to run user logic when state is set to waiting
    ei_printf("INFERENCE_WAITING....\n");
}
void user_inference_sampling()
{
    // if you want to run user logic when state is set to sampling
    ei_printf("INFERENCE_SAMPLING....\n");
}
void user_inference_data_ready()
{
    // if you want to run user logic when state is set to data_ready
    ei_printf("INFERENCE_DATA_READY....\n");
}

void user_inference_default()
{
    // if you want to run user logic when state is default
    ei_printf("default state....\n");
}

void user_timing_and_classification(ei_impulse_result_t *result)
{
    ei_printf("Predictions (DSP: %d ms., Classification: %d ms., Anomaly: %d ms.): \n",
              result->timing.dsp, result->timing.classification, result->timing.anomaly);
    for (size_t ix = 0; ix < EI_CLASSIFIER_LABEL_COUNT; ix++)
    {
        ei_printf("    %s: \t", result->classification[ix].label);
        ei_printf_float(result->classification[ix].value);
        ei_printf("\r\n");
    }
#if EI_CLASSIFIER_HAS_ANOMALY == 1
    ei_printf("    anomaly score: ");
    ei_printf_float(result->anomaly);
    ei_printf("\r\n");
#endif
}


int user_label_detected(ei_impulse_result_t *result) {
    int label_detected = -1;
    for(int i = 0; i < EI_CLASSIFIER_LABEL_COUNT; i++) {
        if(result->classification[i].value > USER_DETECT_THRESHOLD)
        {
            label_detected = i;
        }
    }

    return label_detected;
    //return result->label_detected;
}

void user_display_results(bool continuous_mode, ei_impulse_result_t *result)
{
    if(continuous_mode == true) {
        int label_detected = user_label_detected(result);
        if(label_detected >= 0) {
            ei_printf("LABEL DETECTED : %s\r\n", result->classification[label_detected].label);
            user_timing_and_classification(result);
        }
        else {
            const char spinner[] = {'/', '-', '\\', '|'};
            static char spin = 0;
            ei_printf("Running inference %c\r", spinner[spin]);

            if(++spin >= sizeof(spinner)) {
                spin = 0;
            }
        }
    }
    else {
        user_timing_and_classification(result);
    }
}
