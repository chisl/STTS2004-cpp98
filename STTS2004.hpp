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
		struct EVSD
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000010000000; // [7]
		};
		/* Bits TMOUT: */
		struct TMOUT
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000001000000; // [6]
		};
		/* Bits VHV: */
		struct VHV
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000000100000; // [5]
		};
		/* Bits TRES1: */
		struct TRES1
		{
			static const uint16_t dflt = 0b01; // 2'b1
			static const uint16_t mask = 0b0000000000011000; // [3,4]
		};
		/* Bits Wider_range: */
		struct Wider_range
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000000000100; // [2]
		};
		/* Bits Higher_precision: */
		struct Higher_precision
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000000000010; // [1]
		};
		/* Bits Alarm_and_critical_trips: */
		struct Alarm_and_critical_trips
		{
			static const uint16_t dflt = 0b1; // 1'b1
			static const uint16_t mask = 0b0000000000000001; // [0]
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
	
	/* REG Configuration:
	 */
	struct Configuration
	{
		static const uint16_t __address = 1;
		
		/* Bits Configuration: */
		struct Configuration_
		{
			/* MODE - */
			static const uint16_t dflt = 0b0000000000000000; // 16'h0
			static const uint16_t mask = 0b1111111111111111; // [0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
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
