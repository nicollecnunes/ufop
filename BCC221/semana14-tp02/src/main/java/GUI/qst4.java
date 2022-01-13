package GUI;

import java.util.List;
import javax.swing.DefaultListModel;
import backend.FuncoesTopicos;
import backend.Imovel;

public class qst4 extends javax.swing.JFrame {

    private Menu menu;
    DefaultListModel<String> listModel;

    public qst4() {
        initComponents();
    }

    public qst4(Menu menu) {
        this();
        this.menu = menu;
        this.listModel = new DefaultListModel<>();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        labelTitulo = new javax.swing.JLabel();
        botaoVoltar = new javax.swing.JButton();
        inputValor = new javax.swing.JTextField();
        botaoPesquisar = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        outputResultado = new javax.swing.JList<>();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        labelTitulo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        labelTitulo.setText("Filtrar imóveis por número mínimo de quartos");

        botaoVoltar.setText("Voltar");
        botaoVoltar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoVoltarActionPerformed(evt);
            }
        });

        inputValor.setText("Número");
        inputValor.setToolTipText("");
        inputValor.setName(""); // NOI18N
        inputValor.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                inputValorActionPerformed(evt);
            }
        });

        botaoPesquisar.setText("Pesquisar");
        botaoPesquisar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoPesquisarActionPerformed(evt);
            }
        });

        jScrollPane1.setViewportView(outputResultado);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(botaoVoltar, javax.swing.GroupLayout.PREFERRED_SIZE, 106, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(labelTitulo, javax.swing.GroupLayout.DEFAULT_SIZE, 502, Short.MAX_VALUE)
                .addContainerGap())
            .addComponent(inputValor)
            .addComponent(botaoPesquisar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jScrollPane1)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(labelTitulo)
                    .addComponent(botaoVoltar))
                .addGap(18, 18, 18)
                .addComponent(inputValor, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(botaoPesquisar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(25, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botaoVoltarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoVoltarActionPerformed
        this.dispose();
        this.menu.setEnabled(true);
    }//GEN-LAST:event_botaoVoltarActionPerformed

    private void inputValorActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_inputValorActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_inputValorActionPerformed
    private void formWindowClosed(java.awt.event.WindowEvent evt) {
        this.menu.setEnabled(true);
    }
    private void botaoPesquisarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoPesquisarActionPerformed
        int numero = Integer.parseInt(inputValor.getText());
        List<Imovel> resultado = FuncoesTopicos.q4FiltraPorQuartos(numero);
        listModel.removeAllElements();

        for (Imovel imovel : resultado) {
            listModel.addElement("<html>" + imovel.toString() + "</html>");
        }

        outputResultado.setModel(listModel);
    }//GEN-LAST:event_botaoPesquisarActionPerformed

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new qst4().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botaoPesquisar;
    private javax.swing.JButton botaoVoltar;
    private javax.swing.JTextField inputValor;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel labelTitulo;
    private javax.swing.JList<String> outputResultado;
    // End of variables declaration//GEN-END:variables
}
