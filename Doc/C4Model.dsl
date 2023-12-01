workspace {
    !identifiers hierarchical
    // definition of the model *********************************************************
    model {
        user = person "USER" "4100901 Student"
        
        host_pc = softwareSystem "PC for programming and Debug" "ST-Link" {
            tags "External System" 
        }
        
        telnet = softwareSystem "Terminal on the internet" "Telnet" {
            tags "External System" 
        }
        
        lock_system = softwareSystem "Digital Lock System" "Locks and unlocks by a sequence from the keypad or the internet" {
            stm32 = container "STM32L4" "Control the operation of the system" {
                view = component "View" "Update the outputs (GUI and Actuators) accordingly to the model events"
                model = component "Model" "Parse the events from the controllers(keypad and commands) and updates the view"
                comm = component "Command Manager" "Parse the commands from the internet and debug console"
                keypad = component "Keypad Handler" "Parse the events from the keypad"
            }
            keypad = container "Keypad"
            st_link = container "VCOM Port"
            display = container "OLED Display" "I2C"
            esp8266 = container "ESP8266" "UART-WIFI Bridge"
            led = container "LED Driver" "Mocks a door existance"
        }
        
        // external parties related links
        user -> host_pc "Uses Debug console" "YAT"
        user -> lock_system.keypad "Press Keys" "EXTi"
        user -> telnet "Commands for lock system" "Terminal"
        telnet -> lock_system.esp8266 "Commands from the internet" "WIFI"
        host_pc -> lock_system.st_link "Programming and debug" "USB"
        lock_system.st_link -> lock_system.stm32 "Programming and debug" "UART / JTAG"
        
        // UI controller-view-model related links
        lock_system.esp8266 -> lock_system.stm32.comm "Command from the Internet" "UART"
        lock_system.keypad -> lock_system.stm32.keypad "Key pressed" "EXTi"
        lock_system.stm32.comm -> lock_system.stm32.model "Valid command"
        lock_system.stm32.keypad -> lock_system.stm32.model "Valid key"
    
        lock_system.stm32.model -> lock_system.stm32.view "Model Event"
        lock_system.stm32.view -> lock_system.display "UI event" "I2C"
        lock_system.stm32.view -> lock_system.led "LED Control" "GPIO/PWM"
    }
    // definition of the views: context, container, component ***********************
    views {
        theme default
        systemContext lock_system "Context" {
            include *
            autolayout lr
        }
        container lock_system "Container" {
            include *
            autolayout lr  
        }
        component lock_system.stm32 "Component" {
            include *
            autolayout lr
        }
        styles {
            element "External System" {
                background #a0a0a0
            }
        }
    }
}