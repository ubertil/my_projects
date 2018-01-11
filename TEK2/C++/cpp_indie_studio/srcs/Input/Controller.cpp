#include "Input/Controller.hh"

Sprint::Input::Controller::Controller(Sprint::Input::EventReceiver &eventReceiver, irr::f32 deadZone, irr::f32 camSensitivity) :
    eventReceiver(eventReceiver), deadZone(deadZone), camSensitivity(camSensitivity)
{
    this->camMovement[Sprint::Input::Action::FORWARD] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                                irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; pos += vector; cam += vector; returnValue = irr::core::vector3df(pos.X - returnValue.X, /*0*/pos.Y - returnValue.Y, pos.Z - returnValue.Z); return (returnValue);
    };
    this->camMovement[Sprint::Input::Action::LEFT1] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                             irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; cam = this->rotYAxisAtPoint(cam, pos, this->camSensitivity); return (pos - returnValue);
    };
    this->camMovement[Sprint::Input::Action::LEFT2] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                             irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; cam = this->rotYAxisAtPoint(cam, pos, this->camSensitivity); return (pos - returnValue);
    };
    this->camMovement[Sprint::Input::Action::LEFT3] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                             irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; cam = this->rotYAxisAtPoint(cam, pos, this->camSensitivity); return (pos - returnValue);
    };
    this->camMovement[Sprint::Input::Action::LEFT4] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                             irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; cam = this->rotYAxisAtPoint(cam, pos, this->camSensitivity); return (pos - returnValue);
    };
    this->camMovement[Sprint::Input::Action::RIGHT1] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                              irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; cam = this->rotYAxisAtPoint(cam, pos, -this->camSensitivity); return (pos - returnValue);
    };
    this->camMovement[Sprint::Input::Action::RIGHT2] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                              irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; cam = this->rotYAxisAtPoint(cam, pos, -this->camSensitivity); return (pos - returnValue);
    };
    this->camMovement[Sprint::Input::Action::RIGHT3] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                              irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; cam = this->rotYAxisAtPoint(cam, pos, -this->camSensitivity); return (pos - returnValue);
    };
    this->camMovement[Sprint::Input::Action::RIGHT4] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                              irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) {
        irr::core::vector3df returnValue = pos; cam = this->rotYAxisAtPoint(cam, pos, -this->camSensitivity); return (pos - returnValue);
    };
    this->camMovement[Sprint::Input::Action::NOTHING] = [this](irr::core::vector3df &pos, irr::core::vector3df &cam, irr::core::vector3df vector,
                                                               irr::core::vector3df orthoXAxis, irr::core::vector3df orthoYAxis) { return (irr::core::vector3df(0, 0, 0)); };
}

const irr::f32          Sprint::Input::Controller::getCamSensitivity() const
{
    return (this->camSensitivity);
}

const irr::f32          Sprint::Input::Controller::getDeadZone() const
{
    return (this->deadZone);
}

void                    Sprint::Input::Controller::setDeadZone(irr::f32 deadzone)
{
    this->deadZone = deadzone;
}

void                    Sprint::Input::Controller::setCamSensitivity(irr::f32 sensitivity)
{
    this->camSensitivity = sensitivity;
}

irr::core::vector3df	Sprint::Input::Controller::rotXAxis(irr::core::vector3df &pos, double angle)
{
	return (irr::core::vector3df(pos.X, pos.Y * cos(angle) + pos.Z * sin(angle), pos.Y * (-sin(angle)) + pos.Z * cos(angle)));
}

irr::core::vector3df	Sprint::Input::Controller::rotYAxis(irr::core::vector3df &pos, double angle)
{
	return (irr::core::vector3df(pos.X * cos(angle) + pos.Z * (-sin(angle)), pos.Y, pos.X * sin(angle) + pos.Z * cos(angle)));
}

irr::core::vector3df	Sprint::Input::Controller::rotZAxis(irr::core::vector3df &pos, double angle)
{
	return (pos);
}

irr::core::vector3df	Sprint::Input::Controller::rotXAxisAtPoint(irr::core::vector3df &pos,
                                                                   irr::core::vector3df &orig, double angle)
{
	pos -= orig;
	pos = rotXAxis(pos, angle);
	return (pos + orig);
}

irr::core::vector3df	Sprint::Input::Controller::rotYAxisAtPoint(irr::core::vector3df &pos,
                                                                   irr::core::vector3df &orig, double angle)
{
	pos -= orig;
	pos = rotYAxis(pos, angle);
	return (pos + orig);
}
irr::core::vector3df	Sprint::Input::Controller::rotZAxisAtPoint(irr::core::vector3df &pos,
                                                                   irr::core::vector3df &orig, double angle)
{
	pos -= orig;
	pos = rotZAxis(pos, angle);
	return (pos + orig);
}

irr::core::vector3df    Sprint::Input::Controller::mappedAction(const int i,
                                                                irr::core::vector3df &pos,
                                                                irr::core::vector3df &cam) const
{
    irr::core::vector3df    vector((cam.X - pos.X) / 100, (cam.Y - pos.Y) / 100, (cam.Z - pos.Z) / 100);
    irr::core::vector3df    tmp;
    bool                    alreadyMoved[7] = { false };

    if (i < 3)
    {
        for (irr::u32 j = 0; j < irr::KEY_KEY_CODES_COUNT; j++)
            if (this->eventReceiver.isPressed(static_cast<irr::EKEY_CODE>(j)))
            {
                Sprint::Input::Action action = this->eventReceiver.getAction(static_cast<irr::EKEY_CODE>(j));
                if (this->camMovement.find(action) != this->camMovement.end())
                    if (!alreadyMoved[static_cast<int>(action)] && ((2 * i + 1 == static_cast<int>(action)) || (2 * i + 2 ==
                            static_cast<int>(action)) || static_cast<int>(action) == 0))
                        tmp += this->camMovement.at(action)(pos, cam, vector, irr::core::vector3df(vector.Z, 0, -vector.X),
                                                            irr::core::vector3df(-vector.Y, vector.X, 0));
                if (action != Sprint::Input::Action::NOTHING)
                    alreadyMoved[static_cast<int>(action)] = true;
            }
    }
    else
    {
        irr::f32 move = 0.f;
        Sprint::Input::Action   action = Sprint::Input::Action::NOTHING;
        const irr::SEvent::SJoystickEvent &JoystickState = this->eventReceiver.getJoystickState();
        move = static_cast<irr::f32>(JoystickState.Axis[irr::SEvent::SJoystickEvent::AXIS_X] / 32767.);
        if (move > -this->deadZone && move < this->deadZone)
            move = 0;
        if (!irr::core::equals(move, 0.f))
        {
            action = (move < 0.f) ? (Sprint::Input::Action::LEFT4) : (Sprint::Input::Action::RIGHT4);
            tmp += this->camMovement.at(action)(pos, cam, vector, irr::core::vector3df(vector.Z, 0, -vector.X), irr::core::vector3df(-vector.Y, vector.X, 0));
        }
        if (JoystickState.IsButtonPressed(0))
            tmp += this->camMovement.at(Sprint::Input::Action::FORWARD)(pos, cam, vector, irr::core::vector3df(vector.Z, 0, -vector.X), irr::core::vector3df(-vector.Y, vector.X, 0));
    }
    return (tmp);
}
