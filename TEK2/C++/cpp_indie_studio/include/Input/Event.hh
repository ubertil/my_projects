#pragma once
# include <unordered_map>
# include <stdint.h>
# include "Irrlicht/irrlicht.h"

namespace Sprint
{
    namespace Input
    {
        enum class Action : uint16_t
        {
            FORWARD = 0,
            LEFT1,
            RIGHT1,
            LEFT2,
            RIGHT2,
            LEFT3,
            RIGHT3,
            LEFT4,
            RIGHT4,
            NOTHING
        };

        class EventReceiver : public irr::IEventReceiver
        {
        private:
            bool                                                        keyMapState[irr::KEY_KEY_CODES_COUNT];
            std::unordered_map<irr::EKEY_CODE, Sprint::Input::Action>   keymap;
            irr::SEvent::SJoystickEvent                                 joystickState;
        public:
            EventReceiver(void);
            EventReceiver(const EventReceiver &cpy) = delete;
            EventReceiver   &operator=(const EventReceiver &cpy) = delete;
            ~EventReceiver(void) = default;

            Sprint::Input::Action               getAction(const irr::u32 i) const;
            bool                                OnEvent(const irr::SEvent &event) override final;
            bool                                isPressed(const irr::EKEY_CODE keycode) const;
            const irr::SEvent::SJoystickEvent   &getJoystickState(void) const;
        };
    }
}