{
  description = "university practicals";

  inputs.nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";

  outputs = { nixpkgs, ... }:
    let
      forEachSystem = nixpkgs.lib.genAttrs [ "x86_64-linux" "aarch64-darwin" ];
    in
    {
      devShells = forEachSystem (system:
        let
          pkgs = nixpkgs.legacyPackages.${system};
        in
        {
          default = pkgs.mkShell {
            packages = with pkgs; [
              clang-tools
              libsodium
              rustc
              cargo
              clippy
              rustfmt
              rust-analyzer
              go
              gopls
              delve
              dotnet-sdk_10
              csharp-ls
              typst
              tinymist
            ] ++ pkgs.lib.optionals pkgs.stdenv.hostPlatform.isLinux [ pkgs.gdb ];
            RUST_SRC_PATH = "${pkgs.rustPlatform.rustLibSrc}";
            TYPST_FONT_PATHS = "${pkgs.liberation_ttf}/share/fonts:${pkgs.jetbrains-mono}/share/fonts";
            hardeningDisable = [ "fortify" ];
            shellHook = "unset SOURCE_DATE_EPOCH";
          };
        });
    };
}
