#pragma once
# include <memory>
# include <unordered_map>
# include <functional>
# include "Irrlicht/irrlicht.h"
# include "Game/Model.hh"
# include "Input/Event.hh"

namespace Sprint
{
    namespace Input
    {
        class Controller
        {
        private:
            irr::core::vector3df    rotXAxis(irr::core::vector3df &pos, double angle);
            irr::core::vector3df    rotYAxis(irr::core::vector3df &pos, double angle);
            irr::core::vector3df    rotZAxis(irr::core::vector3df &pos, double angle);
            irr::core::vector3df    rotXAxisAtPoint(irr::core::vector3df &pos, irr::core::vector3df &orig, double angle);
            irr::core::vector3df    rotYAxisAtPoint(irr::core::vector3df &pos, irr::core::vector3df &orig, double angle);
            irr::core::vector3df    rotZAxisAtPoint(irr::core::vector3df &pos, irr::core::vector3df &orig, double angle);
            std::unordered_map<Sprint::Input::Action, std::function<irr::core::vector3df(irr::core::vector3df &pos, irr::core::vector3df &cam,
                                                                         irr::core::vector3df vector, irr::core::vector3df orthoXAxis,
                                                                         irr::core::vector3df orthoYAxis)> >   camMovement;
            Sprint::Input::EventReceiver        &eventReceiver;
            irr::f32                            deadZone;
            irr::f32                            camSensitivity;

        public:
            Controller(Sprint::Input::EventReceiver &receiver, irr::f32 deadZone, irr::f32 camSensitivity);
            Controller(const Controller &cpy) = delete;
            Controller& operator&(const Controller &cpy) = delete;
            ~Controller(void) = default;

            const irr::f32                      getDeadZone() const;
            const irr::f32                      getCamSensitivity() const;
            void                                setDeadZone(irr::f32 deadzone);
            void                                setCamSensitivity(irr::f32 sensitivity);
            irr::core::vector3df                mappedAction(const int i, irr::core::vector3df &pos, irr::core::vector3df &cam) const;
        };
    }
}