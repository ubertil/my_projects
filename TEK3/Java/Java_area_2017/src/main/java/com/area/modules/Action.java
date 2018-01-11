package com.area.modules;

public interface Action extends Module {
    void addReaction(Reaction r);
    void update();
}
