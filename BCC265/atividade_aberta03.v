/*
    Nicolle Canuto Nunes - 20.1.4022
    Sthéphany Karoline Soares de Araújo Tezza - 20.1.4027
    Turma BCC265
*/

module controle(clk, B0, B1, B2, E, X0, X1);
    
    input clk, B0, B1, B2, E;
    output reg X0, X1;
    
    reg [5:0] cont;
    reg [4:0] h_acionamento1, duracao_ac1, h_acionamento2, duracao_ac2, duracao_acE;
    reg acionar1, acionar2;
    reg [4:0] relogio, tempo_at1, tempo_at2, tempo_atE;
    reg at1, at2, atE;
    
    initial begin
        duracao_ac2 <= 0;
        duracao_acE <= 0;
        h_acionamento1 <= 0;
        duracao_ac1 <= 0;
        h_acionamento2 <= 0;
        X0 <= 0;
        X1 <= 0;
        cont <= 6'b100000;
    end

    always @(posedge(B1)) begin 
        if(cont == 6'b100000) begin
            h_acionamento1 <= h_acionamento1 + 1;
        end
        if(cont == 6'b010000) begin
            duracao_ac1 <= duracao_ac1 + 1;    
        end
        if(cont == 6'b001000) begin
            acionar1 <= ~acionar1;    
        end
        if(cont == 6'b000100) begin
            h_acionamento2 <= h_acionamento2 + 1;    
        end
        if(cont == 6'b000010) begin
            duracao_ac2 <= duracao_ac2 + 1;    
        end
        if(cont == 6'b000001) begin
            acionar2 <= ~acionar2;    
        end
    end
    
    always @(posedge(B0)) begin 
        cont <= {cont[0], cont[5:1]};
    end

    always @(posedge(B2)) begin 
        duracao_acE <= duracao_acE + 1;
    end
    
    always @(posedge(clk)) begin 
        relogio <= relogio + 1; 
        
        if (acionar1) begin 
            if (duracao_ac1 == tempo_at1) begin 
                at1 <= 0; 
                X0 <= 0; 
            end
            if (h_acionamento1 == relogio) begin 
                tempo_at1 <= 0; 
                X0 <= 1; 
                at1 <= 1;
            end
            if (at1 == 1) begin 
                tempo_at1 <= tempo_at1 + 1;
            end
        end else begin
            if (at1) begin 
                at1 <= 0;
                X0 <= 0; 
            end
        end
        
        if (acionar2) begin 
            if (at2 == 1) begin 
                tempo_at2 <= tempo_at2 + 1; 
            end
            if (duracao_ac2 == tempo_at2) begin 
                at2 <= 0;
                X0 <= 0; 
            end
            if (h_acionamento2 == relogio) begin 
                X0 <= 1; 
                tempo_at2 <= 0;
                at2 <= 1;  
            end
        end else begin
            if (at2) begin 
                at2 <= 0; 
                X0 <= 0; 
            end
        end
        if (atE) begin 
            if (duracao_acE == tempo_atE) begin 
                atE <= 0; 
                X1 <= 0; 
            end
            tempo_atE <= tempo_atE + 1; 
        end
    end

    always @(posedge(E)) begin 
        if (!atE) begin
            atE <= 1; 
            X1 <= 1; 
            tempo_atE <= 0; 
        end
    end

endmodule