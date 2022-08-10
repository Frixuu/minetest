local S = minetest.get_translator("testcustomcontrols")

minetest.register_custom_control("testcustomcontrols:launch", {
	title = S("Launch"),
	category = S("Cool stuff"),
	description = S("Launches you into the air."),
	default_binds = {
		kbm = "Left Control",
	}
})


minetest.register_globalstep(function(delta)
	local online = minetest.get_connected_players()
	for _, player in ipairs(online) do
		local controls = player:get_custom_controls()
		if controls["testcustomcontrols:launch"] == true then
			player:add_velocity(vector.new(0.0, 50.0, 0.0))
		end
	end
end)