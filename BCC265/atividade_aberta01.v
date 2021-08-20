/*
    Nicolle Canuto Nunes - 20.1.4022
    Sthéphany Karoline Soares de Araújo Tezza - 20.1.4027
    Turma BCC265
*/

module Entrada(input fd, input fe, input s, input c, output fechar, output abrir);

    reg fechar, abrir;
    
    always@(*) 
        begin 
            abrir = (fd & ~fe) | (~fd & ~s & ~c);
            fechar = (~fd & fe) | (~fe & ~s & c) | (fd & ~fe & s) | (~fe & s & ~c);
	    end

endmodule 

module top;
    reg fd, fe, s, c;
	wire fechar, abrir;

    initial begin
		fd = 0;
        fe = 0; 
        s = 0;
        c = 0;
	end
     
    always 
        begin
            #1 {fd, fe, s, c} = {fd, fe, s, c} + 1;
        end
    
    initial 
        begin
            #16 $stop;
        end

    initial begin
		$display("\t \tTEMPO \tfd \tfe \ts \tc \tfechar \tabrir");
		$monitor("%d \t%b \t%b \t%b \t%b \t%b \t%b", $time, fd, fe, s, c, fechar, abrir);
	end
    
    Entrada entrada(.fd(fd), .fe(fe), .s(s), 
                    .c(c), .fechar(fechar), .abrir(abrir));

endmodule