local S = minetest.get_translator("testcustomcontrols")

local category = S("Cool stuff")
local key = "testcustomcontrols:launch"
local sensible_default_qwerty = "Left Ctrl"
minetest.register_custom_control(category, key, sensible_default_qwerty)
