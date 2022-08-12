minetest.register_input_action("testcustomcontrols:launch", {
	title = "Launch yourself", -- Title should be visible in keybinding menu
	category = "Cool stuff from mods", -- Categories should be collapsable
	description = "Launches you into the air.", -- Tooltip
	default_binds = {
		kbm = "Left Control",
	}
})


minetest.register_globalstep(function(delta)
	local online = minetest.get_connected_players()
	for _, player in ipairs(online) do
		local controls = player:get_custom_controls()
		if controls["testcustomcontrols:launch"] == true then
			player:add_velocity(vector.new(0.0, 30.0, 0.0) * delta)
		end
	end
end)