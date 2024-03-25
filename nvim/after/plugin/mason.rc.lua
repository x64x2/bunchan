local status, mason = pcall(require, 'mason')
if (not status) then return end
local status, lsp = pcall(require, 'mason-lspconfig')
if (not status) then return end

mason.setup {}

lsp.setup {
  ensure_installed = { 'html', 'css', 'python' }
}
