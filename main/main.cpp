#include <main.h>

// ULP header (autogen)
#include <ulp_prog.h>

#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include <esp32/ulp.h>
#include <esp_sleep.h>
#include <esp_log.h>

#include <cstring>
#include <bitset>

static const char* TAG = "lsh-test";

void app_main(void) {
  ESP_LOGD(TAG, "[%s]: Initializing program memory", __func__);
  ESP_ERROR_CHECK(ulp_load_binary(0, ulp_bin_start,
    (ulp_bin_end - ulp_bin_start) / sizeof(uint32_t)));

  ESP_LOGD(TAG, "[%s]: ulp_wakeup_period=%uus", __func__, 10 * 1000);
  ESP_ERROR_CHECK(ulp_set_wakeup_period(0, 10 * 1000));

  // Start ULP on the io_run entry
  ESP_ERROR_CHECK(ulp_run(&ulp_entry - RTC_SLOW_MEM));

  vTaskDelay(1000 / portTICK_PERIOD_MS);
  
  ESP_LOGI(TAG, "[%s]: bits: \t\t\t%s", __func__,
    std::bitset<16>(0x226).to_string().c_str());
  ESP_LOGI(TAG, "[%s]: Left shift << 8: \t%s", __func__,
    std::bitset<16>(ulp_state1).to_string().c_str());
  ESP_LOGI(TAG, "[%s]: Left shift << 15: \t%s", __func__,
    std::bitset<16>(ulp_state2).to_string().c_str());
  ESP_LOGI(TAG, "[%s]: Left shift << 16: \t%s", __func__,
    std::bitset<16>(ulp_state3).to_string().c_str());
  ESP_LOGI(TAG, "[%s]: Left shift << 17: \t%s", __func__,
    std::bitset<16>(ulp_state4).to_string().c_str());
  ESP_LOGI(TAG, "[%s]: Left shift << 32: \t%s", __func__,
    std::bitset<16>(ulp_state5).to_string().c_str());
}