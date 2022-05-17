{ nixpkgs ? import<nixpkgs>{} }:

with nixpkgs;

stdenv.mkDerivation {
  name = "Game-2048";
  src = ./.;
  buildPhase = "make";
  installPhase = ''
    mkdir -p $out/bin
    cp Game-2048 $out/bin/
  '';
}

