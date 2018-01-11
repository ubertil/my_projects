#include "Input/Event.hh"

Sprint::Input::EventReceiver::EventReceiver(void)
{
	for (irr::u32 i = 0; i < irr::KEY_KEY_CODES_COUNT; ++i)
    {
        this->keymap[static_cast<irr::EKEY_CODE>(i)] = Sprint::Input::Action::NOTHING;
        this->keyMapState[i] = false;
    }
    // Player 1
    this->keymap.at(irr::EKEY_CODE::KEY_KEY_Z) = Sprint::Input::Action::FORWARD;
    this->keymap.at(irr::EKEY_CODE::KEY_KEY_Q) = Sprint::Input::Action::LEFT1;
    this->keymap.at(irr::EKEY_CODE::KEY_KEY_D) = Sprint::Input::Action::RIGHT1;
    // Player 2
    this->keymap.at(irr::EKEY_CODE::KEY_KEY_I) = Sprint::Input::Action::FORWARD;
    this->keymap.at(irr::EKEY_CODE::KEY_KEY_J) = Sprint::Input::Action::LEFT2;
    this->keymap.at(irr::EKEY_CODE::KEY_KEY_L) = Sprint::Input::Action::RIGHT2;
    // Player 3
    this->keymap.at(irr::EKEY_CODE::KEY_UP) = Sprint::Input::Action::FORWARD;
    this->keymap.at(irr::EKEY_CODE::KEY_LEFT) = Sprint::Input::Action::LEFT3;
    this->keymap.at(irr::EKEY_CODE::KEY_RIGHT) = Sprint::Input::Action::RIGHT3;
}

Sprint::Input::Action               Sprint::Input::EventReceiver::getAction(const irr::u32 i) const
{
    if (i >= 0 && i < this->keymap.size())
        return (this->keymap.at(static_cast<irr::EKEY_CODE>(i)));
}

bool                                Sprint::Input::EventReceiver::OnEvent(const irr::SEvent &event)
{
    if (event.EventType == irr::EET_KEY_INPUT_EVENT)
        this->keyMapState[event.KeyInput.Key] = event.KeyInput.PressedDown;
    if (event.EventType == irr::EET_JOYSTICK_INPUT_EVENT && event.JoystickEvent.Joystick == 0)
        joystickState = event.JoystickEvent;
    return (false);
}

bool                                Sprint::Input::EventReceiver::isPressed(const irr::EKEY_CODE keycode) const
{
    return (this->keyMapState[keycode]);
}

const irr::SEvent::SJoystickEvent   &Sprint::Input::EventReceiver::getJoystickState() const
{
    return (this->joystickState);
}