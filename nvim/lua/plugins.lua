local status, packer = pcall(require, 'packer')
if (not status) then
  print("Packer is not installed")
  return
end

vim.cmd [[ packadd packer.nvim ]]

packer.startup(function(use)
  use 'wbthomason/packer.nvim' -- Packer itself
  use 'rebelot/kanagawa.nvim' -- Theme
  use 'folke/tokyonight.nvim'

  use {
    'nvim-lualine/lualine.nvim',
    requires = { 'kyazdani42/nvim-web-devicons', opt = true }
  }

  use 'L3MON4D3/LuaSnip' -- Snippet engine
  use 'neovim/nvim-lspconfig' -- LSP
  use 'onsails/lspkind-nvim'
  use 'hrsh7th/cmp-buffer'
  use 'hrsh7th/cmp-nvim-lsp'
  use 'hrsh7th/nvim-cmp' -- Completion
  use 'saadparwaiz1/cmp_luasnip'
  use "rafamadriz/friendly-snippets" -- a bunch of snippets to use

  use {
    'nvim-treesitter/nvim-treesitter',
    run = ":TSUpdate"
  }
  use 'windwp/nvim-autopairs'
  use 'windwp/nvim-ts-autotag'

  use 'nvim-lua/plenary.nvim' -- Utilities
  use 'nvim-telescope/telescope.nvim'
  use 'nvim-telescope/telescope-file-browser.nvim'

  use 'akinsho/bufferline.nvim'

  use 'norcalli/nvim-colorizer.lua'

  use 'glepnir/lspsaga.nvim'

  use 'lewis6991/gitsigns.nvim'
  use 'dinhhuy258/git.nvim'

  use 'glepnir/dashboard-nvim'

  use 'williamboman/mason.nvim'
  use 'williamboman/mason-lspconfig.nvim'
  use 'elkowar/yuck.vim'
end)
