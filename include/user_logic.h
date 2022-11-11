#ifndef USER_LOGIC_H
#define USER_LOGIC_H

#include "ei_classifier_types.h"

#include "user_settings.h"

void run_user_logic_after_inference(ei_impulse_result_t *result);

void start_user_impulse();

void user_inference_stopped();

void user_inference_waiting();

void user_inference_sampling();

void user_inference_data_ready();

void user_inference_default();

void user_timing_and_classification(ei_impulse_result_t *result);

int user_label_detected(ei_impulse_result_t *result);

void user_display_results(bool continuous_mode, ei_impulse_result_t *result);

#endif
