require("base")
require("highlights")
require("keymaps")
require("plugins")

require("luasnip.loaders.from_vscode").lazy_load()

vim.g.tokyonight_style = "night"
vim.cmd("colorscheme tokyonight")
