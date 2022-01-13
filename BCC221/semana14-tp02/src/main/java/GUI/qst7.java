package GUI;

import backend.FuncoesTopicos;
import backend.Imovel;
import java.util.List;
import java.util.ListIterator;
import javax.swing.DefaultListModel;

public class qst7 extends javax.swing.JFrame {
    private Menu menu;
    List<Imovel> imoveis;
    DefaultListModel<String> listModel;

    public qst7() {
        initComponents();
    }

    public qst7(Menu menu) {
        this();
        this.menu = menu;
        this.listModel = new DefaultListModel<>();
    }
    
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        labelTitulo = new javax.swing.JLabel();
        botaoVoltar2 = new javax.swing.JButton();
        inputNomeProprietario = new javax.swing.JTextField();
        botaoPesquisar = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        outputResultado = new javax.swing.JList<>();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        labelTitulo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        labelTitulo.setText("Buscar por imóveis de um determinado proprietário");

        botaoVoltar2.setText("Voltar");
        botaoVoltar2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoVoltar2ActionPerformed(evt);
            }
        });

        inputNomeProprietario.setText("Nome");
        inputNomeProprietario.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                inputNomeProprietarioActionPerformed(evt);
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
                .addComponent(botaoVoltar2, javax.swing.GroupLayout.PREFERRED_SIZE, 106, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(labelTitulo, javax.swing.GroupLayout.DEFAULT_SIZE, 437, Short.MAX_VALUE)
                .addContainerGap())
            .addComponent(inputNomeProprietario)
            .addComponent(botaoPesquisar, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jScrollPane1)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(labelTitulo)
                    .addComponent(botaoVoltar2))
                .addGap(18, 18, 18)
                .addComponent(inputNomeProprietario, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(botaoPesquisar)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(25, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botaoVoltar2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoVoltar2ActionPerformed
        this.dispose();
        this.menu.setEnabled(true);
    }//GEN-LAST:event_botaoVoltar2ActionPerformed

    private void botaoPesquisarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoPesquisarActionPerformed
        String proprietario = inputNomeProprietario.getText();
        ListIterator<Imovel> iteradores = FuncoesTopicos.q7RetornarIteradores(proprietario);
        listModel.removeAllElements();
        while (iteradores.hasNext()) {
            listModel.addElement("<html>" + iteradores.next().toString() + "</html>");
        }
        outputResultado.setModel(listModel);
    }//GEN-LAST:event_botaoPesquisarActionPerformed

    private void inputNomeProprietarioActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_inputNomeProprietarioActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_inputNomeProprietarioActionPerformed

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new qst7().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botaoPesquisar;
    private javax.swing.JButton botaoVoltar2;
    private javax.swing.JTextField inputNomeProprietario;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel labelTitulo;
    private javax.swing.JList<String> outputResultado;
    // End of variables declaration//GEN-END:variables
}
