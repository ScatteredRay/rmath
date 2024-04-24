{
  description = "RMath multi-precision vector math library.";
  inputs = {
    nixpkgs.url = "nixpkgs";
  };
  outputs = { self, nixpkgs } : {
    packages = let
      system = "x86_64-linux";
      pkgs = import nixpkgs {
        inherit system;
      };
    in {
      "${system}" = {
        default = pkgs.stdenv.mkDerivation {
          pname = "rmath";
          version = "0-unstable";
          nativeBuildInputs = with pkgs; [
          ];
        };
      };
    };
  };
}
