/*
    Nicolle Canuto Nunes - 20.1.4022
    Sthéphany Karoline Soares de Araújo Tezza - 20.1.4027
    Turma BCC265
*/

module letreiro(clock, reset, palavras);
    input clock;
    output reg [2:0] palavras;
    output reg reset;
    
    reg [3:0] contador;
    reg [6:0] acionar;
    
    initial begin
        contador = 0;
        palavras = 0;
        acionar = -1;
        reset = 0;
    end

    always @(clock) begin
        acionar += 1;
    end

    always @(posedge(clock)) begin
        contador += 1;

        if(acionar == 107) begin
            reset = 1;
        end

        if (contador == 10 || reset == 1) begin
            contador = 0;
        end

        if (contador == 0) 
            begin
                palavras = 3'b000;
            end
        else if (contador == 1)
            begin
                palavras = 3'b100;
            end  
        else if (contador == 2)
            begin
                palavras = 3'b110;
            end
        else if (contador == 3)
            begin
                palavras = 3'b111;
            end
        else if (contador == 4)
            begin
                palavras = 3'b100;
            end
        else if (contador == 5)
            begin
                palavras = 3'b011;
            end
        else if (contador == 6)
            begin
                palavras = 3'b000;
            end
        else if (contador == 7)
            begin
                palavras = 3'b111;
            end
        else if (contador == 8)
            begin
                palavras = 3'b010;
            end
        else if (contador == 9)
            begin
                palavras = 3'b001;
            end
        else 
            begin
                palavras = 3'b000;
            end
    end
endmodule

module simulacao;
    reg clock;
    wire [2:0]palavras;
    wire reset;
    
    initial begin
        clock = 0;
    end
    
    always begin
        #1 clock = ~clock;
    end
    
    initial begin
		$display("tempo\tclock\treset\tbar mosca azul");
		$monitor("%5d\t  %b  \t  %b  \t %b    %b    %b", $time, clock, reset, palavras[2], palavras[1], palavras[0]);
    end
    
    initial begin
        #120 $stop;
    end
    
    letreiro modulo(.clock(clock), .reset(reset), .palavras(palavras));
endmodule