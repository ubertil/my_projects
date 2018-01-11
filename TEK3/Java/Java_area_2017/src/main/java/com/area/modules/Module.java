package com.area.modules;

import java.util.List;
import java.util.Map;

public interface Module {
    List<String> getFields();
    void setField(Map<String, String> fields);
}
