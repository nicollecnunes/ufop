{ nixpkgs ? import <nixpkgs> {} } :

let
  inherit (nixpkgs) pkgs;
in

pkgs.stdenv.mkDerivation {
  name = "my-ocaml-env";
  buildInputs = [
    pkgs.opam
    pkgs.rlwrap
    (pkgs.emacs.pkgs.withPackages (epkgs: (with epkgs.melpaStablePackages; [
      # ocamlPackages.dune_3
    ])))
    pkgs.vscode
  ];
}
