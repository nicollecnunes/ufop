package GUI;

import backend.Imovel;
import java.util.ListIterator;

public class Menu extends javax.swing.JFrame {

    public Menu() {
         initComponents();
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        labelTituloMenu = new javax.swing.JLabel();
        botaoQst2 = new javax.swing.JButton();
        botaoQst3 = new javax.swing.JButton();
        botaoQst4 = new javax.swing.JButton();
        botaoQst5 = new javax.swing.JButton();
        botaoQst66 = new javax.swing.JButton();
        botaoQst7 = new javax.swing.JButton();
        botaoQst8 = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        botaoSair = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("Corretora de Imóveis");

        labelTituloMenu.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        labelTituloMenu.setText("Menu de opções");

        botaoQst2.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\man.png")); // NOI18N
        botaoQst2.setText("Verificar existência de um imóvel de um proprietário");
        botaoQst2.setHorizontalTextPosition(javax.swing.SwingConstants.RIGHT);
        botaoQst2.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoQst2ActionPerformed(evt);
            }
        });

        botaoQst3.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\tag.png")); // NOI18N
        botaoQst3.setText("Imprimir imóveis com valor menor que o especificado");
        botaoQst3.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoQst3ActionPerformed(evt);
            }
        });

        botaoQst4.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\bed.png")); // NOI18N
        botaoQst4.setLabel("Imprimir imóveis de acordo com número de quartos");
        botaoQst4.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoQst4ActionPerformed(evt);
            }
        });

        botaoQst5.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\village.png")); // NOI18N
        botaoQst5.setText("Imprimir imóveis ordenados de acordo com o tipo");
        botaoQst5.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoQst5ActionPerformed(evt);
            }
        });

        botaoQst66.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\cityscape.png")); // NOI18N
        botaoQst66.setText("Imprimir imóveis de uma cidade");
        botaoQst66.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoQst66ActionPerformed(evt);
            }
        });

        botaoQst7.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\cityscape.png")); // NOI18N
        botaoQst7.setText("Imprimir imóvel pelo iterador, buscando pelo proprietário");
        botaoQst7.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoQst7ActionPerformed(evt);
            }
        });

        botaoQst8.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\printer.png")); // NOI18N
        botaoQst8.setText("Imprimir coleção de imóveis em arquivo ou na tela");
        botaoQst8.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoQst8ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(botaoQst2, javax.swing.GroupLayout.Alignment.CENTER, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(botaoQst3, javax.swing.GroupLayout.Alignment.CENTER, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(botaoQst4, javax.swing.GroupLayout.Alignment.CENTER, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(botaoQst5, javax.swing.GroupLayout.Alignment.CENTER, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(botaoQst66, javax.swing.GroupLayout.Alignment.CENTER, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addComponent(botaoQst7, javax.swing.GroupLayout.Alignment.CENTER, javax.swing.GroupLayout.DEFAULT_SIZE, 566, Short.MAX_VALUE)
            .addComponent(botaoQst8, javax.swing.GroupLayout.Alignment.CENTER, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(72, 72, 72)
                .addComponent(labelTituloMenu, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addComponent(labelTituloMenu)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                .addComponent(botaoQst2)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(botaoQst3)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(botaoQst4)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(botaoQst5)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(botaoQst66)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(botaoQst7)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(botaoQst8)
                .addGap(0, 13, Short.MAX_VALUE))
        );

        jLabel1.setFont(new java.awt.Font("Eras Bold ITC", 0, 18)); // NOI18N
        jLabel1.setForeground(new java.awt.Color(51, 153, 255));
        jLabel1.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\home.png")); // NOI18N
        jLabel1.setText("Imobiliária UFOP");

        botaoSair.setIcon(new javax.swing.ImageIcon("C:\\Users\\DPCDTI\\Documents\\Pasta\\tp2-poo\\tp2_poo\\src\\main\\java\\GUI\\assets\\exit.png")); // NOI18N
        botaoSair.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                botaoSairActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(20, 20, 20)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addContainerGap())
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(botaoSair, javax.swing.GroupLayout.PREFERRED_SIZE, 67, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addGap(23, 23, 23))))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addContainerGap()
                        .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 53, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(botaoSair)
                        .addGap(18, 18, 18)))
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void botaoQst2ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoQst2ActionPerformed
        this.setEnabled(false);
        new qst2(this).setVisible(true);
    }//GEN-LAST:event_botaoQst2ActionPerformed

    private void botaoQst3ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoQst3ActionPerformed
        this.setEnabled(false);
        new qst3(this).setVisible(true);
    }//GEN-LAST:event_botaoQst3ActionPerformed

    private void botaoSairActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoSairActionPerformed
        System.exit(0);
    }//GEN-LAST:event_botaoSairActionPerformed

    private void botaoQst4ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoQst4ActionPerformed
        this.setEnabled(false);
        new qst4(this).setVisible(true);
    }//GEN-LAST:event_botaoQst4ActionPerformed

    private void botaoQst5ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoQst5ActionPerformed
        this.setEnabled(false);
        new qst5(this).setVisible(true);
    }//GEN-LAST:event_botaoQst5ActionPerformed

    private void botaoQst66ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoQst66ActionPerformed
        this.setEnabled(false);
        new qst6(this).setVisible(true);
    }//GEN-LAST:event_botaoQst66ActionPerformed

    private void botaoQst7ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoQst7ActionPerformed
        this.setEnabled(false);
        new qst7(this).setVisible(true);
    }//GEN-LAST:event_botaoQst7ActionPerformed

    private void botaoQst8ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_botaoQst8ActionPerformed
        this.setEnabled(false);
        new qst8(this).setVisible(true);
    }//GEN-LAST:event_botaoQst8ActionPerformed

    public static void main(String args[]) {
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new Menu().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton botaoQst2;
    private javax.swing.JButton botaoQst3;
    private javax.swing.JButton botaoQst4;
    private javax.swing.JButton botaoQst5;
    private javax.swing.JButton botaoQst66;
    private javax.swing.JButton botaoQst7;
    private javax.swing.JButton botaoQst8;
    private javax.swing.JButton botaoSair;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JLabel labelTituloMenu;
    // End of variables declaration//GEN-END:variables
}
