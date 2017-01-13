#pragma once

#include <AP_HAL/AP_HAL.h>
#include <AP_HAL/Semaphores.h>
#include <AP_HAL/Device.h>

#define TSYS01_ADDR 0x77

class TSYS01 {
public:
	TSYS01(void);

	bool init(void);
	float temperature(void) { return _temperature; }
	bool healthy(void) { return _healthy; }

    AP_HAL::OwnPtr<AP_HAL::Device> _dev;

private:
    float _temperature; // degrees C
    bool _healthy; // we have a valid temperature reading to report
	uint16_t _k[5]; // internal calibration for temperature calculation
	bool _reset(void);
	bool _read_prom(void);
	bool _convert(void);
	uint32_t _read_adc(void);
	uint16_t _read_prom_word(uint8_t word);
	bool _timer(void);
	void _calculate(uint32_t adc);
};
