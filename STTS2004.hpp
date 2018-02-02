/*
 * name:        STTS2004
 * description: 2.2 V memory module temperature sensor with a 4 Kb SPD EEPROM
 * manuf:       ST Microelectronics
 * version:     Version 0.1
 * url:         http://www.st.com/resource/en/datasheet/stts2004.pdf
 * date:        2018-01-31
 * author       https://chisl.io/
 * file:        STTS2004.hpp
 */

/*                                                                                                       *
 *                                   THIS FILE IS AUTOMATICALLY CREATED                                  *
 *                                    D O     N O T     M O D I F Y  !                                   *
 *                                                                                                       */

#include <cinttypes>

/* Derive from class STTS2004_Base and implement the read and write functions! */

/* STTS2004: 2.2 V memory module temperature sensor with a 4 Kb SPD EEPROM */
class STTS2004_Base
{
public:
	/* Pure virtual functions that need to be implemented in derived class: */
	virtual uint16_t read16(uint16_t address, uint16_t n=16) = 0;  // 16 bit read
	virtual void write(uint16_t address, uint16_t value, uint16_t n=16) = 0;  // 16 bit write
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                           REG Pointer                                            *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/* REG Pointer:
	 */
	struct Pointer
	{
		static const uint16_t __address = 255;
		
		/* Bits unused_0: */
		/* must always be written to '0', not setting these bits to '0' may keep the device from performing to specifications.  */
		struct unused_0
		{
			static const uint16_t dflt = 0b0000; // 4'b0
			static const uint16_t mask = 0b0000000011110000; // [4,5,6,7]
		};
		/* Bits Pointer: */
		struct Pointer_
		{
			static const uint16_t mask = 0b0000000000001111; // [0,1,2,3]
			static const uint16_t CAPA = 0b000; // Thermal sensor capabilities B-grade only 16 R 00 EF
			static const uint16_t CONF = 0b001; // Configuration 16 R/W 00 00
			static const uint16_t UPPER = 0b010; // Alarm temperature upper boundary 16 R/W 00 00
			static const uint16_t LOWER = 0b011; // Alarm temperature lower boundary 16 R/W 00 00
			static const uint16_t CRITICAL = 0b100; // Critical temperature 16 R/W 00 00
			static const uint16_t TEMP = 0b101; // Temperature 16 R 00 00
			static const uint16_t MANU = 0b110; // Manufacturer ID 16 R 10 4A
			static const uint16_t ID = 0b111; // Device ID/revision 16 R 22 01
			static const uint16_t TRES = 0b1000; // Temperature resolution register 8 R/W 01
		};
	};
	
	/* Set register Pointer */
	void setPointer(uint16_t value)
	{
		write(Pointer::__address, value, 16);
	}
	
	/* Get register Pointer */
	uint16_t getPointer()
	{
		return read16(Pointer::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                          REG Capability                                           *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG Capability:
	 * This 16-bit register is read-only, and provides the TS capabilities which comply with the
	 * minimum JEDEC TSE2004av specifications (see Table 7 and Table 8 on page 19). The
	 * STTS2004 resolution is programmable via writing to pointer 08 register. The power-on
	 * default value is 0.25 °C/LSB (10-bit).
	 */
	struct Capability
	{
		static const uint16_t __address = 0;
		
		/* Bits reserved_0: */
		/* These values must be set to '0'.  */
		struct reserved_0
		{
			static const uint16_t dflt = 0b00000000; // 8'b0
			static const uint16_t mask = 0b1111111100000000; // [8,9,10,11,12,13,14,15]
		};
		/* Bits EVSD: */
		/* nEVENT behavior upon shutdown (default)  */
		struct EVSD
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000010000000; // [7]
			static const uint16_t Deasserted_when_shutdown = 0b1; // The EVENT pin output is deasserted (not driven) when entering shutdown, and remains deasserted upon exit from shutdown until the next thermal sample is taken, or possibly sooner if EVENT is programmed for comparator mode. In interrupt mode, EVENT may or may not be asserted when exiting shutdown if a pending interrupt has not been cleared.
		};
		/* Bits TMOUT: */
		/* bus timeout support  */
		struct TMOUT
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000001000000; // [6]
			static const uint16_t SMBus_compatible = 0b1; // for STTS2004-SMBus compatible 25 ms - 35 ms
		};
		/* Bits VHV: */
		/* (VHV) high voltage support for A0 (pin 1)  */
		struct VHV
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000000100000; // [5]
			static const uint16_t Voltage_high = 0b1; // STTS2004 supports a voltage up to 10 volts on the A0 pin - (default)
		};
		/* Bits TRES1: */
		/* Temperature resolution  */
		struct TRES1
		{
			static const uint16_t dflt = 0b01; // 2'b1
			static const uint16_t mask = 0b0000000000011000; // [3,4]
			static const uint16_t Rolution_9_bit = 0b00; // bit, 0.5 °C/LSB
			static const uint16_t Rolution_10_bit = 0b01; // 10 bit, 0.25 °C/LSB - default resolution
			static const uint16_t Rolution_11_bit = 0b10; // 11 bit, 0.125 °C/LSB
			static const uint16_t Rolution_12_bit = 0b11; // 12 bit, 0.0625 °C/LSB
		};
		/* Bits Wider_range: */
		struct Wider_range
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000000000100; // [2]
			static const uint16_t Clamped_below_0 = 0b0; // Values lower than 0 °C will be clamped and represented as binary value '0'.
			static const uint16_t Read_below_0 = 0b1; // Temperatures below 0 °C can be read and the Sign bit will be set accordingly
		};
		/* Bits Higher_precision: */
		struct Higher_precision
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000000000010; // [1]
			static const uint16_t Low_accuracy = 0b0; // 
			static const uint16_t High_accuracy = 0b1; // High accuracy ±1 °C over the active range and ±2 °C over the monitoring range (B-grade) (default).
		};
		/* Bits Alarm_and_critical_trips: */
		struct Alarm_and_critical_trips
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000000000001; // [0]
			static const uint16_t Off = 0b0; // Alarm and critical trips turned OFF.
			static const uint16_t On = 0b1; // Alarm and critical trips turned ON.
		};
	};
	
	/* Set register Capability */
	void setCapability(uint16_t value)
	{
		write(Capability::__address, value, 16);
	}
	
	/* Get register Capability */
	uint16_t getCapability()
	{
		return read16(Capability::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                        REG Configuration                                         *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG Configuration:
	 * The 16-bit configuration register stores various configuration modes that are used to set up
	 * the sensor registers and configure according to application and JEDEC requirements (see
	 * Table 9 on page 21 and Table 10 on page 21).
	 * 
	 * The temperature sensor configuration register holds the control and status bits of the
	 * EVENT pin as well as general hysteresis on all limits. To avoid glitches on the EVENT
	 * output pin, users should disable EVENT or CRITICAL functions prior to programming or
	 * changing other device configuration settings.
	 * 
	 * 4.2.1 Event thresholds
	 * All event thresholds use hysteresis as programmed in register address 0x01 (bits 10
	 * through 9) to be set when they de-assert.
	 * 
	 * 4.2.2 Interrupt mode
	 * The interrupt mode allows an event to occur where software may write a '1' to the clear
	 * event bit (bit 5) to de-assert the event Interrupt output until the next trigger condition occurs.
	 * 
	 * 4.2.3 Comparator mode
	 * The comparator mode enables the device to be used as a thermostat. READs and WRITEs
	 * on the device registers will not affect the event output in comparator mode. The event signal
	 * will remain asserted until temperature drops outside the range or is re-programmed to make
	 * the current temperature “out of range”.
	 * 
	 * 4.2.4 Shutdown mode
	 * The STTS2004 features a shutdown mode which disables all power-consuming activities
	 * (e.g. temperature sampling operations), and leaves the serial interface active. This is
	 * selected by setting the shutdown bit (bit 8) to '1'. In this mode, the devices consume the
	 * minimum current (ISHDN), as shown in Table 30 on page 44.
	 * NOTE: Bit 8 cannot be set to '1' while bits 6 and 7 (the lock bits) are set to '1'.
	 * The device may be enabled for continuous operation by clearing bit 8 to '0'. In shutdown
	 * mode, all registers may be read or written to. Power recycling will also clear this bit and
	 * return the device to continuous mode as well.
	 * If the device is shut down while the EVENT pin is asserted, then the Event output will be deasserted
	 * during shutdown. It will remain de-asserted until the device is enabled for normal
	 * operation. Once the device is enabled, it takes tCONV before the device can re-assert the
	 * Event output.
	 */
	struct Configuration
	{
		static const uint16_t __address = 1;
		
		/* Bits reserved_0: */
		/*
		 * These bits will always read ‘0’ and writing to them will have no effect. For future
		 * compatibility, all RFU bits must be programmed as ‘0’
		 */
		struct reserved_0
		{
			static const uint16_t dflt = 0b00000; // 5'b0
			static const uint16_t mask = 0b1111100000000000; // [11,12,13,14,15]
		};
		/* Bits Hysteresis: */
		struct Hysteresis
		{
			static const uint16_t dflt = 0b00; // 2'b0
			static const uint16_t mask = 0b0000011000000000; // [9,10]
			static const uint16_t Disabled = 0b00; // Hysteresis is disabled (default)
			static const uint16_t Enabled_1_5C = 0b01; // Hysteresis is enabled at 1.5 °C
			static const uint16_t Enabled_3C = 0b10; // Hysteresis is enabled at 3 °C
			static const uint16_t Enabled_6C = 0b11; // Hysteresis is enabled at 6 °C
		};
		/* Bits Shutdown_mode: */
		struct Shutdown_mode
		{
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000100000000; // [8]
			static const uint16_t Enabled = 0b0; // TS is enabled, continuous conversion
			static const uint16_t When_shutdown = 0b1; // Shutdown TS when the shutdown, device, and A/D converter are disabled in order to save power. No event conditions will be asserted; when either of the lock bits (bit6 or bit7) is set, then this bit cannot be altered until it is unlocked. It can be cleared at any time.
		};
		/* Bits Critical_lock_bit: */
		struct Critical_lock_bit
		{
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000010000000; // [7]
			static const uint16_t Not_locked = 0b0; // Critical trip is not locked and can be altered (this is the default).
			static const uint16_t Locked = 0b1; // Critical trip register settings cannot be altered. This bit is initially cleared. When set, this bit returns a logic '1' and remains locked until cleared by an internal p
		};
		/* Bits Alarm_lock_bit: */
		struct Alarm_lock_bit
		{
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000001000000; // [6]
			static const uint16_t Not_locked = 0b0; // Alarm trips are not locked and can be altered.
			static const uint16_t Locked = 0b1; // Alarm trip register settings cannot be altered. This bit is initially cleared. When set, this bit returns a logic '1' and remains locked until cleared by an internal power-on reset. These bits can be written to with a single WRITE, and do not require double WRITEs.
		};
		/* Bits Clear_event: */
		/*
		 * Writing to this register has no effect on overall device functioning in comparator mode.
		 * When read, this bit will always return a logic '0' result.
		 */
		struct Clear_event
		{
			/* MODE w */
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000000100000; // [5]
			static const uint16_t No_effect = 0b0; // 
			static const uint16_t Clear = 0b1; // Clears the active event in interrupt mode. The pin is released and will not assert until a new interrupt condition occurs. 
		};
		/* Bits Output_status: */
		/*
		 * NOTE: The actual incident causing the event can be determined from the read temperature
		 * register. Interrupt events can be cleared by writing to the clear event bit (writing to
		 * this bit will have no effect on overall device functioning).
		 */
		struct Output_status
		{
			/* MODE r */
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000000010000; // [4]
			static const uint16_t Not_asserted = 0b0; // Event output condition is not being asserted by this device.
			static const uint16_t Asserted = 0b1; // Event output condition is being asserted by this device via the alarm window or critical trip event.
		};
		/* Bits Event_output_control: */
		struct Event_output_control
		{
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000000001000; // [3]
			static const uint16_t Disabled = 0b0; // Event output disabled (this is the default).
			static const uint16_t Enabled = 0b1; // Event output enabled; when either of the lock bits (bit6 or bit7) is set, this bit cannot be altered until it is unlocked.
		};
		/* Bits Critical_event_only: */
		struct Critical_event_only
		{
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000000000100; // [2]
			static const uint16_t Alarm_or_critical_temp = 0b0; // Event output on alarm or critical temperature event.
			static const uint16_t Temperature_above_critical = 0b1; // Event only if the temperature is above the value in the critical temperature register (TA > TCRIT); when the alarm window lock bit (bit6) is set, this bit cannot be altered until it is unlocked. 
		};
		/* Bits Event_polarity: */
		/*
		 * The event polarity bit controls the active state of the EVENT pin. The EVENT pin is driven to this state
		 * when it is asserted.
		 * NOTE: As this device is used in DIMM (memory modules) applications, it is strongly recommended
		 * that only the active-low polarity (default) is used. This will provide full compatibility
		 * with the STTS2002. This is the recommended configuration for the STTS2004.
		 */
		struct Event_polarity
		{
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000000000010; // [1]
			static const uint16_t Active_low = 0b0; // Active-low Requires a pull-up resistor to set the inactive state of the open-drain output. The power to the pull-up resistor should not be greater than VDD + 0.2 V. Active state is logical “0”.
			static const uint16_t Active_high = 0b1; // Active-high. The active state of the pin is then logical “1”. 
		};
		/* Bits Event_mode: */
		struct Event_mode
		{
			static const uint16_t dflt = 0b0; // 1'b0
			static const uint16_t mask = 0b0000000000000001; // [0]
			static const uint16_t Comparator_output = 0b0; // Comparator output mode (this is the default).
			static const uint16_t Interrupt = 0b1; // Interrupt mode; when either of the lock bits (bit6 or bit7) is set, this bit cannot be altered until it is unlocked.
		};
	};
	
	/* Set register Configuration */
	void setConfiguration(uint16_t value)
	{
		write(Configuration::__address, value, 16);
	}
	
	/* Get register Configuration */
	uint16_t getConfiguration()
	{
		return read16(Configuration::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG Alarm_Upper                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG Alarm_Upper:
	 * Alarm temperature upper boundary trip
	 */
	struct Alarm_Upper
	{
		static const uint16_t __address = 2;
		
		/* Bits Alarm_Upper: */
		struct Alarm_Upper_
		{
			/* MODE - */
			static const uint16_t dflt = 0b0000000000000000; // 16'h0
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register Alarm_Upper */
	void setAlarm_Upper(uint16_t value)
	{
		write(Alarm_Upper::__address, value, 16);
	}
	
	/* Get register Alarm_Upper */
	uint16_t getAlarm_Upper()
	{
		return read16(Alarm_Upper::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG Alarm_Lower                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG Alarm_Lower:
	 * Alarm temperature lower boundary trip
	 */
	struct Alarm_Lower
	{
		static const uint16_t __address = 3;
		
		/* Bits Alarm_Lower: */
		struct Alarm_Lower_
		{
			/* MODE - */
			static const uint16_t dflt = 0b0000000000000000; // 16'h0
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register Alarm_Lower */
	void setAlarm_Lower(uint16_t value)
	{
		write(Alarm_Lower::__address, value, 16);
	}
	
	/* Get register Alarm_Lower */
	uint16_t getAlarm_Lower()
	{
		return read16(Alarm_Lower::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                  REG Critical_Temperature_Trip                                   *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/* REG Critical_Temperature_Trip:
	 */
	struct Critical_Temperature_Trip
	{
		static const uint16_t __address = 4;
		
		/* Bits Critical_Temperature_Trip: */
		struct Critical_Temperature_Trip_
		{
			/* MODE - */
			static const uint16_t dflt = 0b0000000000000000; // 16'h0
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register Critical_Temperature_Trip */
	void setCritical_Temperature_Trip(uint16_t value)
	{
		write(Critical_Temperature_Trip::__address, value, 16);
	}
	
	/* Get register Critical_Temperature_Trip */
	uint16_t getCritical_Temperature_Trip()
	{
		return read16(Critical_Temperature_Trip::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                         REG Temperature                                          *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG Temperature:
	 * Undefined
	 */
	struct Temperature
	{
		static const uint16_t __address = 5;
		
		/* Bits Temperature: */
		struct Temperature_
		{
			/* MODE - */
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register Temperature */
	void setTemperature(uint16_t value)
	{
		write(Temperature::__address, value, 16);
	}
	
	/* Get register Temperature */
	uint16_t getTemperature()
	{
		return read16(Temperature::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                              REG ID                                               *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG ID:
	 * Manufacturer’s ID
	 */
	struct ID
	{
		static const uint16_t __address = 6;
		
		/* Bits ID: */
		struct ID_
		{
			/* MODE - */
			static const uint16_t dflt = 0b0001000001001010; // 16'h104a
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register ID */
	void setID(uint16_t value)
	{
		write(ID::__address, value, 16);
	}
	
	/* Get register ID */
	uint16_t getID()
	{
		return read16(ID::__address, 16);
	}
	
	
	/****************************************************************************************************\
	 *                                                                                                  *
	 *                                          REG Device_Id                                           *
	 *                                                                                                  *
	\****************************************************************************************************/
	
	/*
	 * REG Device_Id:
	 * Device ID/revision
	 */
	struct Device_Id
	{
		static const uint16_t __address = 7;
		
		/* Bits Device_Id: */
		struct Device_Id_
		{
			/* MODE - */
			static const uint16_t dflt = 0b0010001000000001; // 16'h2201
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register Device_Id */
	void setDevice_Id(uint16_t value)
	{
		write(Device_Id::__address, value, 16);
	}
	
	/* Get register Device_Id */
	uint16_t getDevice_Id()
	{
		return read16(Device_Id::__address, 16);
	}
	
	
	/*****************************************************************************************************\
	 *                                                                                                   *
	 *                                    REG Temperature_Resolution                                     *
	 *                                                                                                   *
	\*****************************************************************************************************/
	
	/*
	 * REG Temperature_Resolution:
	 * Temperature resolution register
	 */
	struct Temperature_Resolution
	{
		static const uint16_t __address = 8;
		
		/* Bits Temperature_Resolution: */
		struct Temperature_Resolution_
		{
			/* MODE - */
			static const uint16_t dflt = 0b0000000000000001; // 16'h1
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
		};
	};
	
	/* Set register Temperature_Resolution */
	void setTemperature_Resolution(uint16_t value)
	{
		write(Temperature_Resolution::__address, value, 16);
	}
	
	/* Get register Temperature_Resolution */
	uint16_t getTemperature_Resolution()
	{
		return read16(Temperature_Resolution::__address, 16);
	}
	
};
