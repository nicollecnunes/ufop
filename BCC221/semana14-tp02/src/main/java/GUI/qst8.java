package GUI;

import backend.FuncoesTopicos;
import backend.Imovel;
import java.util.List;
import javax.swing.DefaultListModel;
import javax.swing.JOptionPane;
import javax.swing.JPasswordField;

public class qst8 extends javax.swing.JFrame {
    private Menu menu;
    List<Imovel> imoveis;
    DefaultListModel<String> listModel;
    private boolean opcao;
    
    public qst8() {
        initComponents();
    }
    
    public qst8(Menu menu) {
        this();
        this.menu = menu;
        this.listModel = new DefaultListModel<>();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        labelTitulo = new javax.swing.JLabel();
        botaoVoltar2 = new javax.swing.JButton();
        opcaoArquivo = new javax.swing.JButton();
        jScrollPane1 = new javax.swing.JScrollPane();
        outputResultado = new javax.swing.JList<>();
        opcaoTela = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.DISPOSE_ON_CLOSE);

        labelTitulo.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        labelTitulo.setText("Imprimir coleção de imóveis em arquivo ou na tela");

        botaoVoltar2.setText("Voltar");
        botaoVoltar2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoVoltar2ActionPerformed(evt);
            }
        });

        opcaoArquivo.setText("Imprimir no arquivo");
        opcaoArquivo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                opcaoArquivoActionPerformed(evt);
            }
        });

        jScrollPane1.setViewportView(outputResultado);

        opcaoTela.setText("Imprimir na tela");
        opcaoTela.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                opcaoTelaActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addComponent(botaoVoltar2, javax.swing.GroupLayout.PREFERRED_SIZE, 106, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(labelTitulo, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
            .addComponent(opcaoArquivo, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(jScrollPane1)
            .addComponent(opcaoTela, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING)
                    .addComponent(labelTitulo)
                    .addComponent(botaoVoltar2))
                .addGap(31, 31, 31)
                .addComponent(opcaoTela)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(opcaoArquivo)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(jScrollPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 146, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botaoVoltar2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoVoltar2ActionPerformed
        this.dispose();
        this.menu.setEnabled(true);
    }//GEN-LAST:event_botaoVoltar2ActionPerformed

    private void opcaoArquivoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_opcaoArquivoActionPerformed
        FuncoesTopicos.q8EscreverArquivo(true);
        listModel.removeAllElements();
        JOptionPane.showMessageDialog(null, "Impresso no Arquivo");
    }//GEN-LAST:event_opcaoArquivoActionPerformed

    private void opcaoTelaActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_opcaoTelaActionPerformed
        List<Imovel> resultado = FuncoesTopicos.q8EscreverArquivo(false);
        listModel.removeAllElements();
        for(Imovel imovel : resultado) {
            listModel.addElement("<html>" + imovel.toString() + "</html>");
        }
        outputResultado.setModel(listModel);
    }//GEN-LAST:event_opcaoTelaActionPerformed

    public static void main(String args[]) {

        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new qst8().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botaoVoltar2;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JLabel labelTitulo;
    private javax.swing.JButton opcaoArquivo;
    private javax.swing.JButton opcaoTela;
    private javax.swing.JList<String> outputResultado;
    // End of variables declaration//GEN-END:variables
}
