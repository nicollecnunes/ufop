{ nixpkgs ? import <nixpkgs> {} } :

let
  inherit (nixpkgs) pkgs;
  ocamlPackages = pkgs.ocaml-ng.ocamlPackages;
  #ocamlPackages = pkgs.ocaml-ng.ocamlPackages_4_14;
  #ocamlPackages = pkgs.ocaml-ng.ocamlPackages_latest;
in

pkgs.stdenv.mkDerivation {
  name = "my-ocaml-env";
  buildInputs = [
    ocamlPackages.dune_3
    ocamlPackages.findlib # essential
    ocamlPackages.ocaml
    ocamlPackages.utop
    ocamlPackages.ocaml-lsp
    ocamlPackages.ppx_expect
    ocamlPackages.ppx_deriving
    ocamlPackages.ppx_import
    ocamlPackages.menhir
    
    pkgs.rlwrap

    (pkgs.emacs.pkgs.withPackages (epkgs: (with epkgs.melpaStablePackages; [
      ocamlPackages.dune_3
    ])))

    pkgs.vscode
  ];
}
