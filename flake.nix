{
  description = "Rellikeht's build of suckless tabbed";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixpkgs-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachSystem [
      "x86_64-linux"
      "i686-linux"
      "aarch64-linux"
      "armv7l-linux"
    ] (system: let
      pkgs = nixpkgs.legacyPackages.${system};
      name = "tabbed";
      src = self;
    in {
      packages = {
        default = pkgs.stdenv.mkDerivation {
          inherit name system src;

          PREFIX = "$(out)";
          CC = pkgs.gcc;

          buildInputs = with pkgs; [
            xorg.libX11
            xorg.libXft
          ];

          buildPhase = ''
            make clean
            make
          '';

          installPhase = ''
            mkdir -p $out/bin
            make install
          '';

          meta = with pkgs.lib; {
            homepage = "https://tools.suckless.org/tabbed";
            description = "Suckless tabed, Rellikeht's build";
            license = licenses.mit;
            mainProgram = "tabbed";
            maintainers = ["Rellikeht"];
            platforms = platforms.linux;
          };
        };
      };
    });
}
