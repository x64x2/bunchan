local status, dashboard = pcall(require, 'dashboard')
if (not status) then return end

local home = os.getenv('HOME')

local Center = {}

function Center:new(width)
  local newObj = { width = width, contents = {}, longest_left = 0 }
  self.__index = self
  return setmetatable(newObj, self)
end

function Center:add(icon, desc, shortcut, action)
  local left_length = #(icon .. desc)

  local spaces = string.rep(' ', self.width - #shortcut - left_length)

  table.insert(self.contents, {
    icon = icon,
    desc = desc .. spaces,
    shortcut = shortcut,
    action = action,
  })
end

function Center:content()
  return self.contents
end

local center = Center:new(40)
center:add('   ', 'Recently latest session', 'SPC s l', 'SessionLoad')
center:add('   ', 'Recently opened files', 'SPC f h', 'DashboardFindHistory')
center:add('   ', 'Find file', 'SPC f f', 'Telescope find_files find_command=rg,--hidden,--files')
center:add('   ', 'File browser', 'SPC f b', 'Telescope file_browser')
center:add('   ', 'Find word', 'SPC f w', 'Telescope live_grep')

dashboard.preview_command = 'cat | lolcat -r'
dashboard.preview_file_path = home .. '/.config/nvim/static/wow.txt'
dashboard.preview_file_height = 14
dashboard.preview_file_width = 31
dashboard.custom_footer = { "Wow!" }
dashboard.custom_center = center:content()
