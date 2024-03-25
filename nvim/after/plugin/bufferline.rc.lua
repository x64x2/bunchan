local status, bufferline = pcall(require, 'bufferline')
if (not status) then return end


bufferline.setup {
  options = {
    mode = "tabs",
    separator_style = "slant", -- this is cool
    always_show_bufferline = false,
    show_buffer_close_icons = false,
    show_close_icon = false,
    color_icons = true,
  },
  highlights = {
    fill = { bg = "#2A2A37" },
    separator = { fg = "#2A2A37" },
    separator_selected = { fg = "#1F1F28" },
  }
}


vim.api.nvim_set_keymap('n', '<Tab>', '<cmd>BufferLineCycleNext<cr>', {})
vim.api.nvim_set_keymap('n', '<S-Tab>', '<cmd>BufferLineCyclePrev<cr>', {})
