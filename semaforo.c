#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/clocks.h"

#define led_r 11
#define led_y 12
#define led_g 13

uint8_t i;

struct repeating_timer timer;

void ledinit(){
  for(i = 11; i < 14; i++){
    gpio_init(i);
    gpio_set_dir(i, 1);
    gpio_put(i, 0);
  }
  gpio_put(11, 1);
}
bool repeating_timer_callback(struct repeating_timer *t){
  if (gpio_get(11) == 1 && gpio_get(12) == 0 && gpio_get(13) == 0){
    gpio_put(11, 0);
    gpio_put(12, 1);
  } else if (gpio_get(11) == 0 && gpio_get(12) == 1 && gpio_get(13) == 0){
    gpio_put(12, 0);
    gpio_put(13, 1);
  } else if (gpio_get(11) == 0 && gpio_get(12) == 0 && gpio_get(13) == 1){
    gpio_put(13, 0);
    gpio_put(11, 1);
  }
  return true;
}

int main() {
  stdio_init_all();
  ledinit();
  add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);
  while (true) {
    sleep_ms(1);
  }
}
