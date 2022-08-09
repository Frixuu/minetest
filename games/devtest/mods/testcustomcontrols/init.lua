local S = minetest.get_translator("testcustomcontrols")

minetest.register_custom_control("testcustomcontrols:launch", {
	title = S("Launch"),
	category = S("Cool stuff"),
	description = S("Launches you into the air.")
	default_binds = {
		kbm = "Left Ctrl",
		controller = "LB"
	}
})
