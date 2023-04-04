CREATE VIEW carteira_investimentos AS (
	SELECT 
	
	-- investimento
	
		iv.data_compra,
		iv.quantidade,
		iv.valor_corrente,
		ca.bolsa AS sigla_da_bolsa,
		bv.nome AS nome_da_bolsa,
		bv.indice AS indice_da_bolsa,
		iv.codigo_ativo,
		acao.caixa AS caixa_da_acao,
		acao.tipo AS tipo_da_acao,
		acao.divida AS divida_da_acao,
		fii.setor AS setor_do_fii,
		fii.dy AS dy_do_fii,
		fii.gestora AS gestora_do_fii,
		bdr.empresa_estrangeira AS empresa_estrangeira_bdr,
		bdr.fracao AS fracao_do_bdr,
		bdr.moeda AS moeda_bdr,
		moeda.lastro AS lastro_moeda_bdr,
		moedas_pais.pais AS pais_da_moeda_bdr,
		rf.grupo AS grupo_renda_fixa,
		rf.porcentagem AS porcentagem_rendimento,
		rf.dia_rendimento,
		cons.id_consulta,
	
	-- usuarios
	
		-- pf.codigo_usuario AS codigo_usuario_pf,
		-- pj.codigo_usuario AS codigo_usuario_pj,
		-- fin.codigo_usuario AS codigo_usuario_fi,
		us.codigo AS codigo_usuario,
		fin.tipo AS tipo_fundo_de_investimentos,
		us.nome AS nome_usuario,
		pf.sexo AS sexo_usuario,
		pf.data_nascimento AS data_nascimento_usuario,
		us.login AS login_usuario,
		us.senha AS senha_usuario,
		us.logradouro AS logradouro_usuario,
		us.complemento AS complemento_usuario,
		us.numero AS numero_usuario,
		us.bairro AS bairro_usuario,
		us.cep AS cep_usuario,
		us.cidade AS cidade_usuario,
		us.estado AS estado_usuario,
		tu.telefone AS telefone_usuario,
		pj.cnae,
		pj.situacao_cadastral,
	
	-- analistas
		
		al.nss AS nss_analista,
		al.nome AS nome_analista,
		al.tipo AS tipo_analista,
		al.login AS login_analista,
		al.senha AS senha_analista,
		al.logradouro AS logradouro_analista,
		al.complemento AS complemento_analista,
		al.numero AS numero_analista,
		al.bairro AS bairro_analista,
		al.cep AS cep_analista,
		al.cidade AS cidade_analista,
		al.estado AS estado_analista,
		ta.telefone AS telefone_analista
	
		FROM consulta cons 
	
		RIGHT JOIN resulta_em res ON res.codigo_usuario = cons.codigo_usuario
		RIGHT JOIN investimento iv ON iv.data_compra = res.data_compra
		LEFT JOIN usuario us ON us.codigo = iv.codigo_usuario
		LEFT JOIN analista al ON al.nss = cons.nss_analista
		LEFT JOIN telefone_analista ta ON ta.nss_analista = cons.nss_analista
		LEFT JOIN telefone_usuario tu ON tu.codigo_usuario = iv.codigo_usuario
		RIGHT JOIN classe_ativos ca ON ca.codigo = iv.codigo_ativo
		LEFT JOIN acao ON acao.codigo = iv.codigo_ativo
		LEFT JOIN fii ON fii.codigo = iv.codigo_ativo
		LEFT JOIN bdr ON bdr.codigo = iv.codigo_ativo
		LEFT JOIN renda_fixa rf ON rf.codigo = iv.codigo_ativo
		LEFT JOIN moeda ON bdr.moeda = moeda.abreviacao
		LEFT JOIN moedas_pais ON moedas_pais.moeda = moeda.abreviacao 
		LEFT JOIN bolsa_valores bv ON bv.abreviacao = ca.bolsa
		LEFT JOIN pessoa_fisica pf ON pf.codigo_usuario = us.codigo
		LEFT JOIN pessoa_juridica pj ON pj.codigo_usuario = us.codigo
		LEFT JOIN fundo_investimentos fin ON fin.codigo_usuario = us.codigo
		
		
)